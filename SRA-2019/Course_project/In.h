#pragma once
#define IN_MAX_LEN_TEXT 1024*1024      //������������ ������ ���� 1��
#define IN_CODE_ENDL '\n'              //������ ����� ������
#define MAX_LEN_WORD_SIZE 260
#define STRING_MAX_LEN 254
//������� ������� ����������, ������=��� �������
// ���� 0<= �������� < 256 - �� �������� ������ ��������

#define IN_CODE_TABLE {\
	/*0       1      2      3      4      5      6      7       8     9      A     B      C      D      E     F */\
/*0*/IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::I, IN::E, IN::F, IN::F, IN::F, IN::F, IN::F,\
/*1*/IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
/*2*/IN::S, IN::T, IN::K, IN::T, IN::T, IN::T, IN::T, IN::T, IN::D, IN::D, IN::B, IN::B, IN::D, IN::B, IN::T, IN::B,\
/*3*/IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::D, IN::B, IN::C, IN::B, IN::T,\
/*4*/IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,\
/*5*/IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::A, IN::F, IN::A, IN::T, IN::T,\
/*6*/IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,\
/*7*/IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::D, IN::T, IN::D, IN::F, IN::F,\
\
/*8*/IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
/*9*/IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
/*A*/IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
/*B*/IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
/*C*/IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
/*D*/IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
/*E*/IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
/*F*/IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F \
}

namespace In
{
	struct IN
	{
		enum { E = 500, 		//�E� - ������ ��������� ������;	
			//T-���������� ������, F-������������, I-������������, ����� ��������
			T = 600, 
			F = 700, 
			I = 800, 
			//T-���������� ������, F-������������, I-������������, ����� ��������
			S = 900, 		  //�S� - ������ �������;
			D = 1000,         //�D� - ������� ���������� ������������; 
			K = 1100, 		  //�K� - ������� �������
			C = 1200, 		  //�C� - ������� ���������� ���������; 
			B = 1300, 		  //�B� - ������� �������� ����������;
			A = 1400          //�A� - ������� ��������� ������;
		     };
		
		int size;										//������ ��������� ����
		int lines;
		int ignor;
		unsigned char* text;							//�������� ���
		int code[256] = IN_CODE_TABLE;					//������� ��������: T, F, I, ����� ��������
	};
	struct mass
	{
		char string[MAX_LEN_WORD_SIZE];
		int line;
	};
	struct ArrWord
	{
		mass* arr;
		int size = 1;
		ArrWord(int mxsz);
		void AddInArr(char* word, int len, int line);
		void Split(char* text);
		
	};
	
	IN getin(wchar_t infile[]);						//������ � ��������� ������� �����

}
