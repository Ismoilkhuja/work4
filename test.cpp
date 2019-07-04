// Example 2-10. The same object can load videos from a camera or a file
// 
#include <opencv2/opencv.hpp>
#include <iostream>

void help(char** argv ) {
	std::cout << "\n"
	<< "\nxample 2-10. The same object can load videos from a camera or a file"
    << "\nCall:\n"  
	<< argv[0] <<" [path/image]\n"
	<< "\nor, read from camera:\n"
	<< argv[0]
	<< "\nFor example:\n"
	<< argv[0] << " ../tree.avi\n"
	<< std::endl;
}
	

int main( int argc, char** argv ) {
	
	help(argv);



  cv::namedWindow( "Example 2-10", cv::WINDOW_AUTOSIZE );
  cv::VideoCapture cap;

  if (argc==1) {
    cap.open(0); // open the first camera
  } else {
    cap.open(argv[1]);
  }

  if( !cap.isOpened() ) { // check if we succeeded
    std::cerr << "Couldn't open capture." << std::endl;
    return -1;
  }

  cv::Mat frame;

  cv::Scalar color1(138,117,15),
	     color2(101, 17, 156), 
	     color3(29, 118, 35);
  cv::RNG rng(12345);
  int radius =30;
  int px=400;
  int py =300;
  int x=5;
  int y=5;
  int flag=0;


  for(;;) {

    cap >> frame;
    
    if( frame.empty() ) break; // Ran out of film
    
    cv::circle(frame, cv::Point(px,frame.rows-py),radius, color1);
    cv::rectangle(frame, cv::Point(px-radius,frame.rows-py+radius), cv::Point(px+radius,frame.rows-py-radius), color2);
    cv::putText(frame, "I",cv::Point(px-radius/2,frame.rows-py+radius/2+5),5,3, color3 );


    if (py>=frame.rows-radius or py<=radius) {
	y=-y;
	flag=1;
    }
    if (px>=frame.cols-radius or px<=radius) {
	x=-x;
	flag=1;
    }
    
    if (flag==1){
	color1=cv::Scalar(rng.uniform(0,255), rng.uniform(0, 255), rng.uniform(0, 255));
	color2=cv::Scalar(rng.uniform(0,255), rng.uniform(0, 255), rng.uniform(0, 255));
	color3=cv::Scalar(rng.uniform(0,255), rng.uniform(0, 255), rng.uniform(0, 255));
	flag=0;
    }

    px=px+x;
    py=py+y;
    



    cv::imshow( "Example 2-10", frame );

    if( (char) cv::waitKey(30) >= 0 ) break;

  }

  return 0;

}
