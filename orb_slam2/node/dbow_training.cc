/**
 * File: Demo.cpp
 * Date: November 2011
 * Author: Dorian Galvez-Lopez
 * Description: demo application of DBoW2
 * License: see the LICENSE.txt file
 */

#include <iostream>
#include <vector>

// DBoW2
//#include "DBoW2.h" // defines OrbVocabulary and OrbDatabase
#include "DBoW2.h"

// OpenCV
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/features2d.hpp>
#include <opencv2/opencv.hpp>


#include "orb_slam/type/type.h"

#include <orb_slam/system.h>

#include "orb_slam/common.h"
#include "orb_slam/config.h"
#include "orb_slam/global.h"
#include "orb_slam/init_cfg.hpp"
#include "orb_slam/utils/timing.h"

// feature extraction
#include "orb_slam/type/frame.h"
#include "orb_slam/cv/sp_extractor.h"

using namespace DBoW2;
using namespace std;
using namespace orbslam;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

void loadFeatures(vector<vector<cv::Mat > > &features);
void changeStructure(const cv::Mat &plain, vector<cv::Mat> &out);
void testVocCreation(const vector<vector<cv::Mat > > &features);
void testDatabase(const vector<vector<cv::Mat > > &features);
void testDatabaseStandAlone(const vector<vector<cv::Mat > > &features);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

// number of training images
const int NIMAGES = 4;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

void wait()
{
  cout << endl << "Press enter to continue" << endl;
  getchar();
}

// ----------------------------------------------------------------------------

int main()
{
  vector<vector<cv::Mat > > features;
  loadFeatures(features);
    cout << features.size() << endl;
  cout << features[0].size() << endl;
  cout << features[0][0].size() << endl;
  testVocCreation(features);

  wait();

  testDatabase(features);

    //testDatabaseStandAlone(features);

    return 0;
}

// ----------------------------------------------------------------------------

void loadFeatures(vector<vector<cv::Mat > > &features)
{
  features.clear();
  features.reserve(NIMAGES);

//   cv::Ptr<cv::ORB> orb = cv::ORB::create();

//   cout << "Extracting ORB features..." << endl;
//   for(int i = 0; i < NIMAGES; ++i)
//   {
//     stringstream ss;
//     ss << "images/image" << i << ".png";

//   //std::string s = ss.str();
//     cout << ss.str() << endl;
//     cv::Mat image = cv::imread(ss.str(), 0);
//     cv::Mat mask;
//     vector<cv::KeyPoint> keypoints;
//     cv::Mat descriptors;

//     orb->detectAndCompute(image, mask, keypoints, descriptors);

    cout << "Extracting Superpoints features..." << endl;

    // superpoint params
    cv::Mat mK;
    cv::Mat mDistCoef;

    float fx = 356.1094055175781;
    float fy = 418.0326843261719;
    float cx = 362.7542616160936;
    float cy = 250.18023338917374;

    cv::Mat K = cv::Mat::eye(3, 3, CV_32F);
    K.at<float>(0, 0) = fx;
    K.at<float>(1, 1) = fy;
    K.at<float>(0, 2) = cx;
    K.at<float>(1, 2) = cy;
    K.copyTo(mK);

        // [k1 k2 p1 p2 k3]
    cv::Mat DistCoef(4, 1, CV_32F);
    DistCoef.at<float>(0) = camera::k1;
    DistCoef.at<float>(1) = camera::k2;
    DistCoef.at<float>(2) = camera::p1;
    DistCoef.at<float>(3) = camera::p2;
    const float k3 = camera::k3;
    if (k3 != 0) {
        DistCoef.resize(5);
        DistCoef.at<float>(4) = k3;
    }
    DistCoef.copyTo(mDistCoef);

    
    for (int i = 0; i < NIMAGES; ++i) {
        stringstream ss;
        ss << "images/image" << i << ".png";

        //std::string s = ss.str();
        cout << ss.str() << endl;
        cv::Mat image = cv::imread(ss.str(), 0);
        cv::Mat mask;
        vector<cv::KeyPoint> keypoints;
        //cv::Mat descriptors;

        double timestamp = 0.0;
        //BaseExtractor *mpORBextractorLeft = new BaseExtractor();
        SPExtractor *mpORBextractorLeft = new SPExtractor(800);
        float mbf = 0.0;
        float mThDepth = 0.0;
        Frame *mCurrentFrame = new Frame(image, timestamp, mpORBextractorLeft, mK, mDistCoef, mbf, mThDepth);
        //cout << mCurrentFrame->mDescriptors.size() << endl;
        //features.push_back(mCurrentFrame->mDescriptors);
        //descriptors = mCurrentFrame->mDescriptors;
        cout << mCurrentFrame->mvKeys.size() << endl;
        


        features.push_back(vector<cv::Mat >());
        changeStructure(mCurrentFrame->mDescriptors, features.back());
    }
}

// ----------------------------------------------------------------------------

void changeStructure(const cv::Mat &plain, vector<cv::Mat> &out)
{
  out.resize(plain.rows);

  for(int i = 0; i < plain.rows; ++i)
  {
    out[i] = plain.row(i);
  }
}

// ----------------------------------------------------------------------------

void testVocCreation(const vector<vector<cv::Mat > > &features)
{
  // branching factor and depth levels 
  const int k = 10;
  const int L = 6;
  const WeightingType weight = TF_IDF;
  const ScoringType scoring = L1_NORM;

  OrbVocabulary voc(k, L, weight, scoring);

  cout << "Creating a small " << k << "^" << L << " vocabulary..." << endl;
  voc.create(features);
  cout << "... done!" << endl;

  cout << "Vocabulary information: " << endl
  << voc << endl << endl;

  // lets do something with this vocabulary
  cout << "Matching images against themselves (0 low, 1 high): " << endl;
  BowVector v1, v2;
  for(int i = 0; i < NIMAGES; i++)
  {
    voc.transform(features[i], v1);
    for(int j = 0; j < NIMAGES; j++)
    {
      voc.transform(features[j], v2);
      
      double score = voc.score(v1, v2);
      cout << "Image " << i << " vs Image " << j << ": " << score << endl;
    }
  }

  // save the vocabulary to disk
  cout << endl << "Saving vocabulary..." << endl;
  voc.save("small_voc.yml.gz");
  cout << "Done" << endl;
}

// ----------------------------------------------------------------------------

void testDatabase(const vector<vector<cv::Mat > > &features)
{
  cout << "Creating a small database..." << endl;

  // load the vocabulary from disk
  OrbVocabulary voc("small_voc.yml.gz");
  
  OrbDatabase db(voc, false, 0); // false = do not use direct index
  // (so ignore the last param)
  // The direct index is useful if we want to retrieve the features that 
  // belong to some vocabulary node.
  // db creates a copy of the vocabulary, we may get rid of "voc" now

  // add images to the database
  for(int i = 0; i < NIMAGES; i++)
  {
    db.add(features[i]);
  }

  cout << "... done!" << endl;

  cout << "Database information: " << endl << db << endl;

  // and query the database
  cout << "Querying the database: " << endl;

  QueryResults ret;
  for(int i = 0; i < NIMAGES; i++)
  {
    db.query(features[i], ret, 4);

    // ret[0] is always the same image in this case, because we added it to the 
    // database. ret[1] is the second best match.

    cout << "Searching for Image " << i << ". " << ret << endl;
  }

  cout << endl;

  // we can save the database. The created file includes the vocabulary
  // and the entries added
  cout << "Saving database..." << endl;
  db.save("small_db.yml.gz");
  cout << "... done!" << endl;
  
  // once saved, we can load it again  
  cout << "Retrieving database once again..." << endl;
  OrbDatabase db2("small_db.yml.gz");
  cout << "... done! This is: " << endl << db2 << endl;
}

void testDatabaseStandAlone(const vector<vector<cv::Mat > > &features)
{
    OrbDatabase db2("small_db.yml.gz");
    cout << "... done! This is: " << endl << db2 << endl;
    // and query the database
    cout << "Querying the database: " << endl;

    QueryResults ret;
    for(int i = 0; i < NIMAGES; i++)
    {
        db2.query(features[i], ret, 4);

        // ret[0] is always the same image in this case, because we added it to the 
        // database. ret[1] is the second best match.

        cout << "Searching for Image " << i << ". " << ret << endl;
    }

    cout << endl;

}

// ----------------------------------------------------------------------------


