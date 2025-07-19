namespace MorningStar
{
    partial class Main
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuMain = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.commandsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.startGameToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.scClientsChat = new System.Windows.Forms.SplitContainer();
            this.tbMessage = new System.Windows.Forms.TextBox();
            this.lbClients = new System.Windows.Forms.ListBox();
            this.rtbChat = new System.Windows.Forms.RichTextBox();
            this.menuMain.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.scClientsChat)).BeginInit();
            this.scClientsChat.Panel1.SuspendLayout();
            this.scClientsChat.Panel2.SuspendLayout();
            this.scClientsChat.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuMain
            // 
            this.menuMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.commandsToolStripMenuItem});
            this.menuMain.Location = new System.Drawing.Point(0, 0);
            this.menuMain.Name = "menuMain";
            this.menuMain.Size = new System.Drawing.Size(624, 24);
            this.menuMain.TabIndex = 0;
            this.menuMain.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // commandsToolStripMenuItem
            // 
            this.commandsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.startGameToolStripMenuItem});
            this.commandsToolStripMenuItem.Name = "commandsToolStripMenuItem";
            this.commandsToolStripMenuItem.Size = new System.Drawing.Size(81, 20);
            this.commandsToolStripMenuItem.Text = "Commands";
            // 
            // startGameToolStripMenuItem
            // 
            this.startGameToolStripMenuItem.Name = "startGameToolStripMenuItem";
            this.startGameToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.startGameToolStripMenuItem.Text = "Start game";
            // 
            // scClientsChat
            // 
            this.scClientsChat.Dock = System.Windows.Forms.DockStyle.Top;
            this.scClientsChat.Location = new System.Drawing.Point(0, 24);
            this.scClientsChat.Name = "scClientsChat";
            // 
            // scClientsChat.Panel1
            // 
            this.scClientsChat.Panel1.Controls.Add(this.lbClients);
            // 
            // scClientsChat.Panel2
            // 
            this.scClientsChat.Panel2.Controls.Add(this.rtbChat);
            this.scClientsChat.Panel2.Controls.Add(this.tbMessage);
            this.scClientsChat.Size = new System.Drawing.Size(624, 377);
            this.scClientsChat.SplitterDistance = 129;
            this.scClientsChat.TabIndex = 1;
            // 
            // tbMessage
            // 
            this.tbMessage.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.tbMessage.Location = new System.Drawing.Point(0, 355);
            this.tbMessage.Name = "tbMessage";
            this.tbMessage.Size = new System.Drawing.Size(491, 22);
            this.tbMessage.TabIndex = 0;
            // 
            // lbClients
            // 
            this.lbClients.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lbClients.FormattingEnabled = true;
            this.lbClients.Location = new System.Drawing.Point(0, 0);
            this.lbClients.Name = "lbClients";
            this.lbClients.Size = new System.Drawing.Size(129, 377);
            this.lbClients.TabIndex = 2;
            // 
            // rtbChat
            // 
            this.rtbChat.Dock = System.Windows.Forms.DockStyle.Fill;
            this.rtbChat.Location = new System.Drawing.Point(0, 0);
            this.rtbChat.Name = "rtbChat";
            this.rtbChat.Size = new System.Drawing.Size(491, 355);
            this.rtbChat.TabIndex = 1;
            this.rtbChat.Text = "";
            // 
            // Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(624, 441);
            this.Controls.Add(this.scClientsChat);
            this.Controls.Add(this.menuMain);
            this.Font = new System.Drawing.Font("Segoe UI", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MainMenuStrip = this.menuMain;
            this.Name = "Main";
            this.Text = "MorningStar";
            this.Load += new System.EventHandler(this.Main_Load);
            this.menuMain.ResumeLayout(false);
            this.menuMain.PerformLayout();
            this.scClientsChat.Panel1.ResumeLayout(false);
            this.scClientsChat.Panel2.ResumeLayout(false);
            this.scClientsChat.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.scClientsChat)).EndInit();
            this.scClientsChat.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuMain;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem commandsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem startGameToolStripMenuItem;
        private System.Windows.Forms.SplitContainer scClientsChat;
        private System.Windows.Forms.TextBox tbMessage;
        private System.Windows.Forms.ListBox lbClients;
        private System.Windows.Forms.RichTextBox rtbChat;
    }
}

