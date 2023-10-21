#pragma once
//template<class T> class debugMgr
//{
//
//public:
//	static void PrintData(T inT,String str) {
//		Print << U"{}: {}"_fmt(str, inT);
//	}
//};
//

template <typename T> void DebugPrint(T inT, String str) {
	Print << U"{}: {}"_fmt(str, inT);
}
