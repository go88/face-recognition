#pragma once

#include "opencv2/opencv.hpp"
#include "facedetect-dll.h"

#include <iostream>
#include <io.h>		// _access() ����ͷ�ļ�


using namespace cv;
using namespace std;


namespace go88 {


	// �Զ��幤����
	class Utils {
	public:
		template<typename Out>
		static void SPLIT(const string s, char delim, Out result);

		// �ַ����ָ��
		static vector<string> SPLIT(const string s, char delim);

		// �ж�·���Ƿ���ڣ��ļ���Ŀ¼�������ж�
		static int IS_EXIST_PATH(string path);

		// ��·���л���ļ���·��
		static string GET_FOLDER(string path);

		// ʹ��system md ������ļ������Զ༶Ŀ¼
		static int CREATE_FOLDER(string folder_path);

		// ��os�����ȡĿ¼���ļ�����
		static int GET_FILES_NUM(string dir, string cach_path = "tempCMD.dat");

		// ��ȡ CSV �ļ�
		// ���� vector<vector<string>>
		// ����� vector[i] ����һ��
		// ����� vector[i] ����һ��
		static vector<vector<string>> READ_CSV(const string& file_name, char separator = ';');

		// ������һ������ͼƬ��Χ��Ϊ0-255 uint8����
		static Mat NORM(InputArray input);

		// ͼƬԤ������
		// ���룺�� capture >> frame �õ���frame
		// ������Ƿ�����ȷ������
		// ���ã�vector<Mat> faces ����ͼ��
		//		 vector<Rect> rects ����ͼ���� frame ��λ�� Rect
		static int PRETREATMENT(Mat frame, vector<Mat>& faces, vector<Rect> & rects);

		// ������⺯��
		// �� libfacedetect �� facedetect_multiview �������з�װ
		//		float scale,	scale factor for scan windows
		//		int min_neighbors,	how many neighbors each candidate rectangle should have to retain it
		//		int min_object_width,	Minimum possible face size. Faces smaller than that are ignored.
		//		int max_object_width = 0,	Maximum possible face size. Faces larger than that are ignored. It is the largest posible when max_object_width=0.
		//		int doLandmark = 0	landmark detection
		static void FACEDETECT_MULTIVIEW(Mat &frame_gray, vector<Rect> &face_rects, float scale = 1.1f,
			int min_neighbors = 3, int min_object_width = 48, int max_object_width = 0, int doLandmark = 0);
	};
}
