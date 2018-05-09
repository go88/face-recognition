#pragma once

#include "opencv2/opencv.hpp"

#include <mutex>	// ������

#include "tinyxml2.h"	// ���л�ʱ��д xml �Ŀ�

#include "go88_lib.h"


using namespace cv;
using namespace std;
using namespace tinyxml2;


namespace project_common {


	// Common �����Ļ��������ͱ���
	class Com {
	public:
		// �õ� instance ʵ�� ����ģʽ
		static Com* INS();

		// ��Щ���� xml �ļ��г�ʼ��
		// <?>val</?>
		// ���л�·��
		string SERIALIZATION_PATH;
		// ����ͼƬ·��
		string FACES_FOLDER;
		// lbph ���׼ȷ��
		float LBPH_PCT;


		// ���л� ·��Ϊ SERIALIZATION_PATH
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


	private:
		//����ģʽ���캯��˽��
		Com();

		// ����ʵ��ָ��
		static Com* _instance;

		// ��������
		// ���л���xml <num>"?"</num>
		int _int_num;

		// �������֣�key:id val:name ��ֵ��
		// ���л���xml <id_name>
		//					<id_name_pair>
		//						<id>?</id>
		//						<name>?</name>
		//					</id_name_pair>
		//			   </id_name>
		map<int, string> _map_id_name;

		// �������ֺ�ͼƬ������key:name val:index Ŀ¼�������һ��ͼƬ�����
		// ���л���xml <name_index>
		//					<name_index_pair>
		//						<name>?</name>
		//						<index>?</index>
		//					</name_index_pair>
		//			   </name_index>
		map<string, int> _map_name_index;

		// ��Ƭ·���ͱ�ǩ img1;0
		// ���л���xml <images_labels>
		//					<images_labels_pair>
		//						"img_src":0
		//					</name_index_pair>
		//			   </images_labels>
		vector<string> _vct_images_labels;
	};
}