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
  for (int row = 0; row < bmp.size(); row++)
  {
    
  // Go through column in row and repeat for how many columns(pixels)  there are
    for (int column = 0; column < bmp[row].size(); column++)
    {
      rgb = bmp[row][column];
      int sum = rgb.red + rgb.green + rgb.blue;
      int avg = sum / 3;
  // Change pixel from a R,G,B image to a grayscale image from 0 - 255
      rgb.red = avg;
      rgb.green = avg;
      rgb.blue = avg;
      bmp[row][column] = rgb;
      image.fromPixelMatrix(bmp);
      image.save("oldTimeyPhoto.bmp");
    }
  }
 


  return 0;
}
