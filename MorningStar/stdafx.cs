using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Common;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Runtime.InteropServices;
using System.Security.Permissions;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using System.Xml.Schema;
using static System.Net.Mime.MediaTypeNames;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Window;

namespace MorningStar
{
    public class stdafx
    {
        // Store member information.
        public ref struct MemberInfo
        {
            IPEndPoint IP_EP;
            UInt16 ID;
            // Find other MemberInfo in Properties.Settings.Default.
        }

        // Backup member information.
        public ref struct MemberInfoBackup
        {
            IPEndPoint IP_EP;
            UInt16 ID;
        }

        public class Profile
        {
            public
                static List<String> ProfileList = new List<String>();
            String[] SystemSection = { "System", "State", "Color" };
        }


        // To anyone reading this, know that if you change this once it works, it's on you to fix it, enough sanity was lost here today
        // EDIT - 5 mins later, replace enough with too fkin much

        // KGT2KGAME
        const uint P1_INPUT = 0x004259C0;
        const uint P2_INPUT = 0x004259C4;
        const uint SINGLE_CONTROL_HOOK = 0x00414712;
        // THIS ONE LINE WAS A CODING BREAKTHROUGH, BUT A MENTAL BREAKDOWN
        // Two heads turned out to be better than one, probably saved like 60 seconds at best
        // 61 GOTO 52
        //END
        // Tralalero tralala caused less pain
        static byte[] SINGLE_CONTROL_HOOK_CODE = new byte[] { 0xCC, 0x90, 0x90, 0x90, 0x90, 0x90 };
        const uint VS_CONTROL_HOOK = 0x00414748;
        static byte[] VS_CONTROL_HOOK_CODE = new byte[] { 0x6A, 0x00 };
        const uint STORY_KEY = 0x00414729;
        static byte[] STORY_KEY_CODE = new byte[] { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        const uint VS_P1_KEY = 0x0041474A;
        //static byte[] VS_P1_KEY_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint VS_P2_KEY = 0x00414764;
        //static byte[] VS_P2_KEY_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint RANDOM_SEED = 0x0041FB1C;
        //const uint RAND_FUNC = 0x00417A22;
        //static byte[] RAND_FUNC_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint HIT_JUDGE = 0x0042470C;
        //const uint HIT_JUDGE_SET = 0x00414C90;
        //static byte[] HIT_JUDGE_SET_CODE[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint DEFAULT_ROUND = 0x00430124;
        //const uint ROUND_SET = 0x00414AFC;
        //static byte[] ROUND_SET_CODE[] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint TEAM_ROUND = 0x00430128;
        //const uint TEAM_ROUND_SET = 0x00414ADB;
        //static byte[] TEAM_ROUND_SET_CODE[] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint DEFAULT_TIMER = 0x00430114;
        //const uint TIMER_SET = 0x00414A8C;
        //static byte[] TIMER_SET_CODE[] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint VS_ROUND = 0x0040897F;
        //static byte[] VS_ROUND_CODE[] = { 0xCC };
        //const uint ROUND_ESI = 0x004EDCAC;
        //const uint ROUND_END = 0x00409715;
        //static byte[] ROUND_END_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint P1_HP = 0x004DFC85;
        //const uint P1_MAX_HP = 0x004DFC91;
        //const uint P1_STATE = 0x0047033E;
        //const uint P2_HP = 0x004EDCC4;
        //const uint P2_MAX_HP = 0x004EDCD0;
        //const uint P2_STATE = 0x004704BC;
        //const uint STAGE_SELECT = 0x00408756;
        //static byte[] STAGE_SELECT_CODE = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint FRAME_RATE = 0x00404C37;
        //static byte[] FRAME_RATE_CODE = { 0xCC, 0x90 };
        //const uint BGM_VOLUME = 0x0040347E;
        //const uint SE_VOLUME = 0x0040348C;
        //const uint VOLUME_SET_1 = 0x00403401;
        //static byte[] VOLUME_SET_1_CODE[] = {0x58,0x8B,0x08,0x6A,0x01,0xEB,0x0D,0x58,0x8B,0x08,0x6A,0x00,0xEB,0x06,0x90,0xE9,
        //                          0xEB,0x21,0x01,0x00,0x6A,0x00,0x6A,0x00,0x50,0xFF,0x51,0x30,0x5B,0xC3};
        //const uint VOLUME_SET_2 = 0x0040347B;
        //static byte[] VOLUME_SET_2_CODE[] = {0x50,0x8B,0x08,0xCC,0x52,0x50,0xFF,0x51,0x3C,0xE9,0x78,0xFF,0xFF,0xFF,0x50,0x8B,
        //                          0x08,0xCC,0x52,0x50,0xFF,0x51,0x3C,0xE9,0x71,0xFF,0xFF,0xFF};

        // KGT95GAME
        const uint P1_INPUT_95 = 0x00437750;
        const uint P2_INPUT_95 = 0x00437754;
        const uint INPUT_COUNTER_95 = 0x00437700;
        const uint UNCHECK_JOYSTICK_95 = 0x00402A33;
        //static byte[] UNCHECK_JOYSTICK_95_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint CONTROL_HOOK1_95 = 0x0040902B;
        //static byte[] CONTROL_HOOK1_95_CODE[] = { 0xE8, 0xB0, 0xFA, 0xFF, 0xFF };
        //const uint CONTROL_HOOK2_95 = 0x00409053;
        //static byte[] CONTROL_HOOK2_95_CODE[] = { 0xE8, 0x88, 0xFA, 0xFF, 0xFF };
        //const uint STORY_P1_KEY_95 = 0x0040901C;
        //static byte[] STORY_P1_KEY_95_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint STORY_P2_KEY_95 = 0x00409030;
        //static byte[] STORY_P2_KEY_95_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint VS_P1_KEY_95 = 0x0040904C;
        //static byte[] VS_P1_KEY_95_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint VS_P2_KEY_95 = 0x00409058;
        //static byte[] VS_P2_KEY_95_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint RANDOM_SEED_95 = 0x004243FC;
        //const uint RAND_FUNC_95 = 0x0041A864;
        //static byte[] RAND_FUNC_95_CODE = { 0xCC, 0x90, 0x90, 0x90, 0x90 };
        //const uint HIT_JUDGE_95 = 0x00432740;
        //const uint HIT_JUDGE_SET_95 = 0x004029E9;
        //static byte[] HIT_JUDGE_SET_95_CODE = 0x90, 0x90, 0x90, 0x90, 0x90;
        //const uint DEFAULT_TIMER_95 = 0x00432754;
        //const uint TIMER_SET_95 = 0x00402A68;
        //static byte[] TIMER_SET_95_CODE[] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
        //const uint P1_WIN_95 = 0x005E9914;
        //const uint P2_WIN_95 = 0x005E9978;
        //const uint VS_ROUND_95 = 0x00411661;
        //static byte[] VS_ROUND_95_CODE[] = { 0xCC, 0x90 };
        //const uint ROUND_END_95 = 0x00413410;
        //static byte[] ROUND_END_95_CODE[] = { 0xCC, 0x90 };
        //const uint STAGE_SELECT_95 = 0x0041162C;
        //static byte[] STAGE_SELECT_95_CODE[] = { 0xCC, 0x90, 0x90, 0x90, 0x90, 0x90 };
        const uint FRAME_RATE_95 = 0x00404759;
        static byte[] FRAME_RATE_95_CODE = new byte[] { 0xCC, 0x90 };
        const uint BGM_VOLUME_95 = 0x00402042;
        const uint SE_VOLUME_95 = 0x00402050;
        const uint VOLUME_SET_1_95 = 0x00401FC8;
        static byte[] VOLUME_SET_1_95_CODE = new byte[] { 0x58, 0x8B, 0x08, 0x6A, 0x01, 0xEB, 0x16, 0x90, 0xE9, 0xCB, 0x85, 0x01, 0x00, 0x58, 0x8B, 0x08, 0x6A, 0x00, 0xEB, 0x09, 0x90, 0x90, 0x90, 0x90, 0xE9, 0xAB, 0x85, 0x01, 0x00, 0x6A, 0x00, 0x6A, 0x00, 0x50, 0xFF, 0x51, 0x30, 0x5B, 0xC3 };
        const uint VOLUME_SET_2_95 = 0x0040203F;
        static byte[] VOLUME_SET_2_95_CODE = new byte[] { 0x50, 0x8B, 0x08, 0xCC, 0x52, 0x50, 0xFF, 0x51, 0x3C, 0xE9, 0x7B, 0xFF, 0xFF, 0xFF, 0x50, 0x8B, 0x08, 0xCC, 0x52, 0x50, 0xFF, 0x51, 0x3C, 0xE9, 0x7A, 0xFF, 0xFF, 0xFF };

        // Determines MS version integer.
        const uint MS_VERSION = 100;

        const uint MAX_ID = 0x3FFF;

        // Reference of maximums.
        //const uint MAX_NAME = 32;
        //const uint MAX_ARRAY = 64;
        //const uint MAX_TITLE = 256;
        //const uint MAX_PACKET = 512;
        //const uint MAX_WELCOME = 512;
        //const uint MAX_KEYWORD = 256;
        //const uint MAX_PROFILE = 2048;

        static byte[] TYMT_VERSTION = new byte[] { 6 };
        const uint TIME_OUT = 3000;

        // Team rounds be wilding.
        const uint MAX_TEAM_ROUND = 4;

        // Are you ready for the pain?
        struct MT_SP_INFORMATION
        {
            bool DEBUG;
            bool RAND_SEARCH;
            bool INITIALIZED;
            bool SHOW_TOP;
            bool KGT2K;
            uint SEED;
            uint MAX_STAGE;
            uint STAGE_SELECT;
            uint ROUND;
            uint TIMER;
            IntPtr PROCESS;
            uint PROCESS_ID;
            IntPtr HWND;
            bool CONTROL;  // 0:P1 1:P2
            char P1_NAME, MAX_NAME;
            char P2_NAME, MAX_NAME2;
            char ORIGINAL_TITLE, MAX_TITLE;
            char TITLE, MAX_TITLE;
            int VOLUME;
            bool VERSION_CHECKED;
            uint P_HP;
            bool WINNER; // 0:P1 1:P2
            bool TEAM_ROUND_HP;
            bool SERVER_MODE;
            uint SERVER_MODE_PORT;
            bool ERRORED;
        }

        public struct MT_SP_OPTION
        {
            char PATH, MAX_PATH;
            uint CONNECTION_TYPE;
            char SERVER_NAME[MAX_NAME];
            char CONNECTION_IP[MAX_ARRAY];
            char WELCOME[MAX_WELCOME];
            uint BOOKMARK_COUNT;
            uint BOOKMARK_DELETED_COUNT;
            char BOOKMARK_SERVER_NAME[MAX_TITLE][MAX_ARRAY];
	        char BOOKMARK_CONNECTION_IP[MAX_NAME][MAX_ARRAY];
	        char BOOKMARK_CONNECTION_TYPE[MAX_NAME][MAX_ARRAY];
	        char BOOKMARK_PORT[MAX_NAME][MAX_ARRAY];
	        char GAME_EXE[_MAX_PATH];
            char REPLAY_FOLDER[_MAX_PATH];
            char VS_SOUND[_MAX_PATH];
            bool VS_SOUND_ENABLE;
            char NOTICE_SOUND[_MAX_PATH];
            bool NOTICE_SOUND_ENABLE;
            char ENTER_SOUND[_MAX_PATH];
            bool ENTER_SOUND_ENABLE;
            char NAME_SOUND[_MAX_PATH];
            bool NAME_SOUND_ENABLE;
            char TALK_SOUND[_MAX_PATH];
            bool TALK_SOUND_ENABLE;
            char SEEK_SOUND[_MAX_PATH];
            bool SEEK_SOUND_ENABLE;
            char KEYWORD_SOUND[_MAX_PATH];
            bool KEYWORD_SOUND_ENABLE;
            char KEYWORD[MAX_KEYWORD];
            char NAME[MAX_NAME];
            char COMMENT[MAX_NAME];
            char LOOKING[MAX_NAME];
            char AVOIDING[MAX_NAME];
            char REGION[MAX_NAME];
            char GG[MAX_NAME];
            bool GG_ENABLE;
            uint PORT;
            uint OPEN_PORT;
            uint AUTO_SAVE;
            uint MAX_CONNECTION;
            uint BGM_VOLUME;
            uint SE_VOLUME;
            uint MAX_STAGE;
            uint STAGE_SELECT;
            uint ROUND;
            uint TIMER;
            bool TEAM_ROUND_HP;
            uint SIMULATE_DELAY;
            bool HIT_JUDGE;
            bool DISPLAY_NAME;
            bool DISPLAY_VERSUS;
            bool DISPLAY_FRAMERATE;
            bool DISPLAY_RAND;
            bool REPLAY_DIVIDE;
            bool CHANGE_WINDOW_SIZE;
            uint CHAT_HISTORY;
            uint DELAY;
            uint INTERVAL;
            uint REPLAY_VERSION;
            bool RECORD_REPLAY;
            bool ALLOW_SPECTATOR;
            bool LOG_WORDWRAP;
            bool LOG_LOCK;
            bool LOG_FORMAT_RTF;
            bool NAME_FLASH;
            bool TALK_FLASH;
            bool REST_CONNECT;
            bool AFTER_REST;
            bool AUTO_REST;
            uint AUTO_REST_TIME;
            bool GET_IP_ENABLE;
            bool SHOW_GAME_OPTION;
            bool SHOW_RESULT;
            bool LOG_CLEAR_WITHOUT_WELCOME;
            char PROFILE[MAX_ARRAY];
            char PROFILE_LIST[MAX_PROFILE];
            uint PROFILE_INDEX;
            bool LEGACY_SERVER;
            bool SHOW_REGION;
            bool DARK_MODE;
            bool SYS_TRAY;
        }

        public struct MT_SP_WINDOW_STATE
        {
            int LEFT;
            int TOP;
            int WIDTH;
            int HEIGHT;
            int SPLITTER;
            int DIALOG_LEFT;
            int DIALOG_TOP;
        }

        public struct MT_SP_COLOUR
        {
            uint SERVER_NAME;
            uint HOST_NAME;
            uint CLIENT_NAME;
            uint REST_STATE;
            uint VS_STATE;
            uint WATCH_STATE;
            uint SEEK_STATE;
            uint SYSTEM_MESSAGE;
            uint ERROR_MESSAGE;
            uint DEBUG_MESSAGE;
            uint NOTICE_BACK;
            uint COMMENT_BACK;
            uint SECRET;
        }

        public struct REPLAY_DATA
        {
            UInt16 KEY;
            byte[] COUNT;
        }

        public struct REPLAY_INFO
        {
            char VERSION;
            bool CONTROL;
            UInt16 KEY[2];
            byte[] COUNT[2];

            std::deque<REPLAY_DATA> DEQUE[2];
        }

        public enum CONNECTION_TYPE
        {
            CT_SERVER,
            CT_HOST,
            CT_CLIENT,
            CT_FREE,
        }

        public enum SERVER_MODE
        {
            SM_NORMAL,
            SM_MIX,
            SM_MATCH,
            SM_NORA,
        }

        public enum MEMBER_STATE
        {
            MS_FREE,
            MS_REST,
            MS_VS,
            MS_WATCH,
            MS_COUCH,
            MS_READY,
            MS_SEEK,
        }

        public enum LIST_VIEW
        {
            LV_NAME,
            LV_COMMENT,
            LV_BLIND,
        }

        public enum RUN_TYPE
        {
            RT_FREE = 1,
            RT_VS,
            RT_PLAYBACK,
            RT_WATCH,
        }

        public enum MT_SP_PACKET_HEADER
        {
            PH_PING,
            PH_PONG,
            PH_REQ_CONNECTION,   // 1:protocol 1:name_l n:name 1:comment_l n:comment
            PH_REQ_CONNECTION_H, // HOST‚ÈÚ‘±—v‹
            PH_RES_CONNECTION,   // 1:server_name_l n:server_name 2:ID 1:name_l n:name 1:comment_l n:comment 1:state
            PH_MESSAGE,          // 2:ID 1:msg_l n:msg
            PH_NOTICE,           // 1:len n:notice
            PH_REQ_LIST,         // 2:ID 0‚Å‘Sˆõ•ª
            PH_RES_LIST,         // 2:ID 1:name_l n:name 1:comment_l n:comment 1:state 4:IP 2:Port + ˆÃ†
            PH_NEW_MEMBER,       // ã‚Æ“¯‚¶
            PH_QUIT,             // 2:ID
            PH_LOST,             // 2:ID
            PH_CHANGE_STATE,     // 2:ID 1:STATE
            PH_REQ_STATE,        // 2:ID
            PH_RES_STATE,        // 2:ID 1:STATE
            PH_CHANGE_COMMENT,   // 2:ID 1:comment_l n:comment
            PH_DICE,             // 1:value
            PH_REQ_VS,           // 2:ID 4:ŽÀsƒtƒ@ƒCƒ‹‚ÌƒnƒbƒVƒ…
            PH_RES_VS,           // 1:state
            PH_REQ_VS_PING,      // 1:ID 5ŒÂƒoƒ‰‚Åsend
            PH_RES_VS_PONG,      // 1•bŠÔ‚É4ŒÂˆÈãŽóM‚Å‘ÎíŠJŽn
            PH_REQ_VS_SETTING,   // 1:delay local‚Æhost‚Å‘å‚«‚È’l‚É‚ ‚í‚¹‚é
            PH_RES_VS_SETTING,   // 1:delay 4:seed 1:max_stage 1:stage 1:round 1:timer
            PH_VS_DATA,          // 4:frame n:data 4*delayŒÂ•ª‘—M
            PH_REQ_VS_DATA,      // 4:frame ƒpƒPƒbƒg—ˆ‚Ä‚È‚¢‚Ì‚Å‹Ù‹}—v¿
            PH_RES_VS_DATA,      // 4:frame 2:input
            PH_VS_END,
            PH_REQ_WATCH,        // 2:ID
            PH_RES_WATCH,        // 1:state 2:P1ID 2:P2ID 4:seed 1:max_stage 1:stage 1:round 1:timer  state = 0:ŠÏíŠJŽn 1`:ŠÏí•s‰Â
            PH_WATCH_DATA,       // 4:frame 40:10ƒtƒŒ[ƒ€•ª‚Ìƒf[ƒ^
            PH_WATCH_END,        // 2:ID Ž©•ª‚Ì‚Æ“¯‚¶ID‚È‚çŠÏíI—¹A‘¼‚ÌID‚È‚çƒŠƒXƒg‚©‚çíœ
            PH_SECRET,           // 1:type n:type‚²‚Æ‚É‚¢‚ë‚¢‚ë
        }

        public enum SECRET_TYPE
        {
            ST_PING,             // 4:time
            ST_PONG,
        }

        public enum VERSUS_SEQUENCE {
            VS_REQ,
            VS_PING,
            VS_SETTING,
            VS_STANDBY,
            VS_DATA,
            VS_END,
            VS_TIMEOUT,
            VS_ERROR,
        }

        extern MT_SP_INFORMATION MTINFO;
        extern MT_SP_OPTION MTOPTION;
        extern MT_SP_WINDOW_STATE MTWS;
        extern MT_SP_COLOR MTCOLOR;

        public class PacketPacker
        {
            public
                PacketPacker()
                {
                    Length = 0;
                    Packet = new Array byte[] (MAX_PACKET);
                }
            protected
                 ~PacketPackee()
                {
                if (Packet != null)
                {
                    Packet.dispose();
                }
                }
        }

        public class PacketDivider
        {
            public
                int Length;
            Array<byte[]> Packet;

            PacketDivider(Array<BYTE>% datagram)
	        {       
		        Length = 0;
		        Packet = datagram;
	        }

	BYTE Divide(){
		return Packet[Length++];
	}

	array<BYTE>^ Divide(int length){
		array<BYTE>^ data = gcnew array<BYTE>(length);

		Array::Copy(Packet, Length, data, 0, length);
		Length += length;

		return data;
	}

        }

        void WriteErrorLog(String text, String caption)
        {
            DirectoryInfo[] cDirs = new DirectoryInfo(Properties.Settings.Default.NAME).GetDirectories();
            using (StreamWriter sw = new StreamWriter("error.log", true, Encoding.Default))
                try
                {
                    sw.WriteLine();
                }
                finally
                {
                    if (sw != null)
                    {
                        sw.Close();
                        sw.Dispose();
                    }
                }
        }
        
        void ApplicationThreadException(Object sender, ThreadExceptionEventArgs e)
        {
            WriteErrorLog(e.ToString(), "ThreadException");
            //MTINFO.ERRORED = true;

            if (SERVER_MODE != true)
            {
                return;
            }
            MessageBox.Show("An exception occurred in the MorningStar thread and has been written to the error.log file.\n\nAttempt to recover?", "Thread Exception", MessageBoxButtons.OK, MessageBoxIcon.Error);
            try
            {
                return;
            }
            catch (Exception ex)
            {
                MessageBox.Show("MorningStar will now exit.", "Recovery Failed", MessageBoxButtons.OK, MessageBoxIcon.Error);
                System.Windows.Forms.Application.Exit();
            }
        }

        void ApplicationUnhandledException(Object sender, UnhandledExceptionEventArgs e)
        {
            WriteErrorLog(e.ToString(), "UnhandledException");
            //MTINFO.ERRORED = true;

            if (!MTINFO.SERVER_MODE)
            {
                MessageBox.Show("A unhandled exception occurred in the LilithPort thread and has been written to the error.log file.\n\nMorningStar will attempt to recover.", "Unhandled Exception", MessageBoxButtons.OK, MessageBoxIcon.Error);
                try
                {
                    return;
                }
                catch (Exception ex){
                    MessageBox.Show("MorningStar will now exit.", "Recovery Failed", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    System.Windows.Forms.Application.Exit();
                }
            }
        }

        void LoadMTOption()
        {

        }

        void SaveMTOption()
        {

        }
    }
}
