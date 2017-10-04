#include "bitmap.h"
#include<vector>
#include<iostream>

using namespace std;

int main()
{
  Bitmap image;
  vector <vector <Pixel> > bmp;
  Pixel rgb;
  // Ask user for file name of image
  string fileName;
  cout << "What is the name of the file you want to convert?" << endl;
  // Store user input
  cin >> fileName;
  // Open File
  image.open(fileName);
  bmp = image.toPixelMatrix();
  cout << fileName << " has been loaded. It is " << bmp[0].size() <<" pixels wide and "<< bmp.size() << " pixels high." << endl;
  // Go through row 1 of image and repeat for as many rows there are
  // Go through column in row and repeat for how many columns(pixels)  there are
  // Change pixel from a R,G,B image to a grayscale image from 0 - 255
  // Create new file from output of previous step
  return 0;
}
