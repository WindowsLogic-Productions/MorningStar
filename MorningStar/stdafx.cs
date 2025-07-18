using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using static System.Net.Mime.MediaTypeNames;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Window;
using System.IO;
using System.Data;
using System.Net;
using System.Runtime.InteropServices;

namespace MorningStar
{ 
    public class stdafx
    {
        // Store member information.
        public ref struct MemberInfo
        {
            IPEndPoint IP_EP;
            String NAME;
            String COMMENT;
            String LOOKING;
            String AVOIDING;
            String REGION;
            String GG;
            UInt16 ID;
            uint TYPE;
            uint NUM_VS;
            uint RESPONSE;
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

        void WriteErrorLog(String text, String caption)
        {
           
            DirectoryInfo[] cDirs = new DirectoryInfo(Properties.Settings.Default.Path).GetDirectories();

            //new String(test) + "error.log", Encoding.Default
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
        }
    }
}
