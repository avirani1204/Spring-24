// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : Student Name                    Environment : ubuntu:bionic               //
//  Date ......: 2021/02/10                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

#include "image_ppm.hpp"
#include "pixel.hpp"
#include "seam_carver.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("True == True", "") { REQUIRE(true == true); }

TEST_CASE("GetVerticalSeam - image1.ppm", "[get_vseam]") {
  ImagePPM image("/workspaces/mp-4-seam-carving-avirani1204/images/image1.ppm");
  SeamCarver sc(image);
  int kGroundtruth[3][4] = {
      {150, 600, 600, 900}, {75, 75, 450, 450}, {75, 525, 525, 450}};

  int** energy = sc.GetEnergyArr();

  int** dp = sc.FindVertMinPath(energy);
  for (int i = 0; i < sc.GetHeight(); ++i) {
    for (int j = 0; j < sc.GetWidth(); ++j) {
      REQUIRE(dp[i][j] == kGroundtruth[i][j]);
    }
  }

  //   for (int i = 0; i < sc.GetHeight(); ++i) {
  //     for (int j = 0; j < sc.GetWidth(); ++j) {
  //       std::cout << energy[i][j] << " ";
  //     }
  //     std::cout << std::endl;
  //   }
  int array[3] = {0, 0, 0};
  int* vert_seam = sc.GetVerticalSeam();
  for (int i = 0; i < sc.GetHeight(); ++i) {
    std::cout << array[i] << " " << vert_seam[i] << std::endl;
    REQUIRE(array[i] == vert_seam[i]);
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////