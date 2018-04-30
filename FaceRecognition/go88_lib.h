#pragma once

#include "opencv2/opencv.hpp"
#include <iostream>
#include <io.h>


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
		// ��ȡ csv �ļ���ת��Ϊ Mat �� label ����Ϊ��������

		// ������һ������ͼƬ��Χ��Ϊ0-255 uint8����
		static Mat NORM(InputArray input);

		// ͼƬԤ������
		// ���룺�� capture >> frame �õ���frame
		//		 model_path ʹ�õ� xml �ļ�·��
		// ������Ƿ�����ȷ������
		// ���ã�vector<Mat> faces ����ͼ��
		//		 vector<Rect> rects ����ͼ���� frame ��λ�� Rect
		static int PRETREATMENT(Mat frame, vector<Mat>& faces, vector<Rect> & rects, string model_path);
	};
}
