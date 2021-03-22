#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
Mat src, dst1, dst2, dst3,dst4,dst5;
int BoxValue = 10;
int BlurValue = 10;
int GaussianValue = 10;
int MiddleValue = 10;
int DoubleValue = 10;
static void on_Box(int, void *);
static void on_Blur(int, void *);
static void on_Gaussian(int, void *);
static void on_Middle(int, void *);
static void on_Double(int, void *);

int main()
{
	system("color5E");
	src = imread("moutain.jpg");
	dst1 = src.clone();
	dst2 = src.clone();
	dst3 = src.clone();
	dst4 = src.clone();
	dst5 = src.clone();
	namedWindow("【原图】", 1);
	imshow("【原图】", src);
	namedWindow("【方框滤波】", WINDOW_AUTOSIZE);
	createTrackbar("内核值", "【方框滤波】", &BoxValue, 40, on_Box);
	on_Box(BoxValue, 0);
	namedWindow("【均值滤波】", WINDOW_AUTOSIZE);
	createTrackbar("内核值", "【均值滤波】", &BlurValue, 40, on_Blur);
	on_Blur(BlurValue, 0);
	namedWindow("【高斯滤波】", WINDOW_AUTOSIZE);
	createTrackbar("内核值", "【高斯滤波】", &GaussianValue, 40, on_Gaussian);
	on_Gaussian(GaussianValue, 0);
	namedWindow("【中值滤波】", WINDOW_AUTOSIZE);
	createTrackbar("内核值", "【中值滤波】", &MiddleValue, 40, on_Middle);
	on_Middle(MiddleValue, 0);
	namedWindow("【双边滤波】", WINDOW_AUTOSIZE);
	createTrackbar("内核值", "【双边滤波】", &DoubleValue, 40, on_Double);
	on_Double(DoubleValue, 0);
	waitKey(0);
	return 0;
}

static void on_Box(int, void *)
{
	boxFilter(src, dst1, -1, Size(BoxValue + 1, BoxValue + 1));
	imshow("【方框滤波】", dst1);
}
static void on_Blur(int, void *)
{
	blur(src, dst2, Size(BlurValue + 1, BlurValue + 1),Point(-1,-1));
	imshow("【均值滤波】", dst2);
}
static void on_Gaussian(int, void *)
{
	GaussianBlur(src, dst3,Size(GaussianValue*2+1, GaussianValue*2+1),0,0);
	imshow("【高斯滤波】", dst3);
}
static void on_Middle(int, void *)
{
	medianBlur(src, dst4, MiddleValue*2+1);
	imshow("【中值滤波】", dst4);
}
static void on_Double(int, void *)
{
	bilateralFilter(src, dst5,DoubleValue,DoubleValue*2,DoubleValue/2);
	imshow("【双边滤波】", dst5);
}
