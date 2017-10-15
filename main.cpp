#include "bitmap.h"
#include<vector>
#include<iostream>
#include<ctime>

using namespace std;

int main()
{
  Bitmap image;
  vector <vector <Pixel> > bmp;
  Pixel rgb;
  srand (time(NULL));
  // Ask user for file name of image
  string fileName;
  cout << "What is the name of the file you want to convert?" << endl;
  // Store user input
  cin >> fileName;
  // Open File
  image.open(fileName);
  bool validBmp = image.isImage();
  if( validBmp == true)
  {
    bmp = image.toPixelMatrix();
  }
  else{
    do{
    cout << "File provided cannot be properly read as a bitmap image, the file must be a 24 bit depth Windows BMP file. Enter valid file name." << endl;
    cin >> fileName;
    image.open(fileName);
    validBmp = image.isImage();
    }
    while(validBmp == false);
      bmp = image.toPixelMatrix();
  }
  cout << fileName << " has been loaded. It is " << bmp[0].size() <<" pixels wide and "<< bmp.size() << " pixels high." << endl;
  // Ask if you want film grain on the photo
/*  cout << "Would you like film grain on the photo? (Y/N)" << endl;
  string choiceGrain;
  cin >> choiceGrain;
  if (choiceGrain == "y" || choiceGrain == "Y")
  {
    cout << "How much grain would you like? (0-100)" << endl;
    int amtGrain;
    cin >> amtGrain;
  } 
*/
  // Go through row 1 of image and repeat for as many rows there are
  for (int row = 0; row < bmp.size(); row++)
  {

  // Go through column in row and repeat for how many columns(pixels)  there are
    for (int column = 0; column < bmp[row].size(); column++)
    {
      rgb = bmp[row][column];
      int sum = rgb.red + rgb.green + rgb.blue;
      int avg = sum / 3;
  // Apply the grain to photo
/*      if ( choiceGrain == "y" || choiceGrain == "Y" )
      {
        int amtGrain;
        amtGrain = ( rand() % amtGrain);
               cout << "amt grain is : " << amtGrain << endl;
      }
*/
  // Change pixel from a R,G,B image to a grayscale image from 0 - 255
      rgb.red = avg;
      rgb.green = avg;
      rgb.blue = avg;
      bmp[row][column] = rgb;
    }
  }
  image.fromPixelMatrix(bmp);
  image.save("oldTimeyPhoto.bmp");
 


  return 0;
  }
