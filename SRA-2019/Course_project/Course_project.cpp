
#include "stdafx.h"
#include <iostream>
#include <locale>
#include <cwchar>

#include "Rules.h"
#include "Error.h"
#include "Parm.h"

#include "In.h"
#include "Log.h"
#include "LexicalAnalyse.h"
#include "MFST.h"
#include "MFST_TRACE.h"
#include "Polish_Notation.h"
#include "SemanticAnalyse.h"
#include "CodeGeneration.h"

#define FILE_PATH_ASM "F:/������/Kurs/SRA-2019/ASM/ASM.asm"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "");
	bool Param_Ok = false;
	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		Param_Ok = true;
		log = Log::getlog(parm.log);
		Log::WriteLine(log, "����:", "��� ������ ", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		//std::cout << "\tIN get parametrs. \n";
		Log::WriteIn(log, in);

		//���� ������������ �������
		std::cout << "\n����� ������������ �����������. \n";
		In::ArrWord arr(4096);
		//std::cout << "\tIN Arrword get max size. \n";
		arr.Split((char*)in.text);
		//std::cout << "\tAnalyssis of the code table. \n";
		LT::LexTable lextable = LT::Create(LT_MAXSIZE);
		//std::cout << "\tLexical table is created. \n";
		IT::IdTable idtable = IT::Create(TI_MAXSIZE);
		//std::cout << "\tIndentification table is created. \n";
	
		if (!Lex::LexicalAnalyse(arr, lextable, idtable, log))
		{
			std::cout << "\n����������� ������ ��������.\n";

			//���� ��������������� �������
			std::cout << "\n����� ��������������� �������.\n";
			MFST::Mfst mfst(lextable, GRB::greibach);
		//	std::cout << "\tIndentification table is created. \n";
			std::cout << "\n����� �������. \n";
			if (mfst.start(log))
			{
				std::cout << "\n������� ��������. \n";
				mfst.printrules(log);
				/*GRB::Print_Rules(GRB::greibach);*/
				std::cout << "\n�������������� ������ ��������.\n";
				std::cout << "\n����� �������������� �������.\n";
				std::cout << "\t���� ������ ��� �� ��������, �������� �������� ��� � ��������� �����.\n";

				//���� �������������� �������
				if (!SA::SemanticAnalyse(log, lextable, idtable))
				{
					std::cout << "\n������������� ������ ��������.\n";

					//���������
					std::cout << "\n������ ��������� ����.\n";
					CG::ConstSegment CnstS(idtable.size);
					CG::DataSegment Data(idtable.size);
					CG::CodeSegment Code;
					CG::add(idtable, CnstS);
					CG::add(idtable, Data);
					CG::CodeSegmentGeneration(Code, lextable, idtable);
					CG::startGeneration(FILE_PATH_ASM, CnstS, Data, Code);
					std::cout << "\n��������� ���� ���������.\n";

				}
				else
				{
					std::cout << "\n�������� � ����������!\n";
				}
			}
			else
			{
				std::cout << "\n�������� � ����������!\n";
			}
		}
		else
		{
			std::cout << "\n�������� � ��������!\n";
		}
	}
	catch (Error::ERROR e)
	{
		if (e.id == 100)
			std::cout << "�������� -in  ����������!\n";
		else if(e.id==104)
			std::cout << "��������� ����� �������� ���������\n";
		else
		{
			
			Log::WriteError(log, e);
		}

	}

	if (Param_Ok)
		Log::Close(log);
//	std::cout << "\nStart Compilation\n";
//	system("start F:\\������\\Kurs\\SRA-2019\\compilation.bat");
//	std::cout << "\nEnd Compilation\n";
	return 0;
}
