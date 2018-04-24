#include "opencv2/opencv.hpp"

#include "go88_lib.h"

using namespace cv;
using namespace std;
using namespace my_ocv_project_common_180418;

int create_new_face();
int check_face();


int init() {
	{
		using namespace go88;
		// ���·�������ڣ�����Ŀ¼����Ĭ��INS�������л� �洢
		if (!Utils::IS_EXIST_PATH(Com::PROTO_PATH)) {
			Utils::CREATE_FOLDER(Utils::GET_FOLDER(Com::PROTO_PATH));
			Com::INS()->serialization();
		}
		else {
			// ·�����ھͷ����л�
			Com::INS()->un_serialization();
		}

	}
	return 0;
}


int face_recognition() {

	init();

	int c = 0;
	while (c != 2) {
		cout << "����������0�����������1���˳���2��" << endl;
		cin >> c;

		if (c == 0) {
			create_new_face();
		}
		else if (c == 1) {
			check_face();
		}
	}
	return 0;
}