#ifndef GO88_LIB_H
#define GO88_LIB_H

#include "opencv2/opencv.hpp"
#include <iostream>
#include <fstream>
#include <io.h>

#include "my_proto.MsgCom.pb.h"

using namespace cv;
using namespace std;


namespace my_ocv_project_common_180418 {


	// Common �����Ļ��������ͱ���
	class Com {
	public:
		// �õ� instance ʵ�� ����ģʽ
		static Com* INS();

		// ���л�·��
		static const string PROTO_PATH;
		// ����ͼƬ·��
		static const string FACES_FOLDER;

		// ���л� ·��Ϊ PROTOPATH
		int serialization();
		// �����л�
		int un_serialization();

		// �õ���������
		int get_num();

		// ������������
		void set_num(int num);

		// ͨ���������ֵõ�����ķ���id
		int get_id(string name);

		// ��������ķ���id
		string get_name(int id);

		// �õ�һ�������ͼƬindex����1��ʼ
		int get_index(string name);

		// ����һ�������ͼƬindex
		int set_index(string name, int index);

		// �Ƿ�������������
		int is_exist_name(string name);

		// �Ƿ���ڴ˷���id
		int is_exist_id(int id);

		// ���key:id val:name ��ֵ��
		map<int, string>& get_id_name();

		// �������ֺ�ͼƬindex
		map<string, int>& get_name_index();

		// ��Ƭ·���ͱ�ǩ
		vector<string>& get_img_lb();

		// cascade ģ���ļ�·��
		string get_cascade_path();

	private:
		//����ģʽ���캯��˽��
		Com();

		// ����ʵ��ָ��
		static Com* _instance;

		// ��������
		// ���л���proto  int32
		int _int_num;

		// �������֣�key:id val:name ��ֵ��
		// ���л���proto ����һ��string���� "{0;id0}{1;id1}{2;id2}"
		map<int, string> _map_id_name;

		// �������ֺ�ͼƬ������key:name val:index Ŀ¼�������һ��ͼƬ�����
		// ���л���proto ����һ��string���� "{name0;8}{name1;3}{name2;9}"
		map<string, int> _map_name_index;

		// ��Ƭ·���ͱ�ǩ img1;0
		// ���л���proto ����һ��string���� "{img1;0}{img2;0}{img3;1}"
		vector<string> _vct_images_labels;

		// cascade ģ���ļ�·��
		// ���л���proto string
		string _str_cascade_path;
	};
}

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

#endif // !GO88_LIB_H