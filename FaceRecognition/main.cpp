#include "opencv2/opencv.hpp"


int test_video();
int test_face();
int test_capture();
int face_recognition();


int main(void)
{
	// �������û���
	/*String filePath = "D:/Program Files/opencv/sources/samples/data/lena.jpg";
	Mat img = imread(filePath);
	imshow("lena", img);
	resize(img, img, Size(img.cols/2, img.rows/2));
	imshow("resize", img);
	waitKey(0);*/

	// ��Ƶȡ����ͼƬ
	//test_video();
	// ���ͼƬ�е�����
	//test_face();
	// �������ͷ�е�����
	//test_capture();
	face_recognition();
	
	return 0;
}