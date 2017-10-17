// Name: Ali Alneyadi

#include <iostream>
#include "bitmap.h"
#include <string>
#include <vector>

using namespace std;

int main () 

{ 
  Bitmap image;
  vector <vector <Pixel> > bmp;
  Pixel rgb;
  string bmpFile;

  // Ask the user for the file name
  cout<<"File name : "<<endl;
  getline(cin,bmpFile);

  image.open(bmpFile);

  // Keep asking for the file name if it is not a valid bmp file!
  while (image.isImage()==false)
  {
    cout<<"Please enter a 24 bit depth Windows BMP image."<<endl;
    cout<<"Try again!!"<<endl;
    cout<<"File name : "<<endl;
    getline(cin,bmpFile);
    image.open(bmpFile);
  }

  bmp = image.toPixelMatrix();
 
  cout<<bmpFile<<" has been loaded. it is "<<bmp[0].size()<<" pixels wide and "<<bmp.size()<<" pixels high."<<endl;


  // Make the oldtimey bmp
  for(int row=0;row<bmp.size();row++)
  {
    for(int col=0;col<bmp[row].size();col++)
    {
      // Make each pixel the average of the rgb
      int avg;
      avg = bmp[row][col].red;
      avg += bmp[row][col].green;
      avg += bmp[row][col].blue;
      avg /= 3;

      rgb.red = avg;
      rgb.blue = avg;
      rgb.green = avg;

      bmp[row][col] = rgb;
    }
  }
  // All done
  image.fromPixelMatrix(bmp);
  image.save("oldtimey.bmp");
  cout<<"Saved the grayscale version of the image "<<bmpFile<<" as oldtimey.bmp!"<<endl;

  return 0; 
} 
