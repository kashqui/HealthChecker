#using <System.dll>
#include "Result.cpp"
#include "GetIp.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace System::Net::NetworkInformation;
using namespace System::Runtime::InteropServices;

class TP
{
public:
	void getHeartBeat()
	{
		// Set target IP address.
		GetIp get;
		System::String^ ip = get.getIp();
		String^ ip_ai = ip->Split(';')[0];
		String^ ip_vi = ip->Split(';')[1];
	
		List<System::String^>^ i_list = gcnew List<System::String^>();
		for each (String^ item in ip->Split(';'))
		{
			if (item != "")	i_list->Add(item);
		}
		// Ping'em.
		System::String^ msg = "";		
		Ping^ pingSender = gcnew Ping;
		PingOptions^ options = gcnew PingOptions;
		// Change the fragmentation behavior.
		options->DontFragment = true;
		int timeout = 5;
		for (int i = 0; i < i_list->Count; i++)
		{
			PingReply^ reply = pingSender->Send(i_list[i], timeout);
			// Add success flag as message.
			if (reply->Status == IPStatus::Success)
			{
				msg += "1";
			}
			else
			{
				msg += "0";
			}
		}
		//Convert System::String^ to std::string
		std::string std_msg;
		IntPtr ptr = Marshal::StringToHGlobalAnsi(msg);
		std_msg = static_cast<const char*>(ptr.ToPointer());
		Marshal::FreeHGlobal(ptr);
		// Output result.
		Result res;
		res.exportResult(std_msg);
	}
};
