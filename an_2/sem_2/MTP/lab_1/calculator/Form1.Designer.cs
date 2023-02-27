namespace calculator
{
    partial class calculatorForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(calculatorForm));
            this.exprTextBox = new System.Windows.Forms.RichTextBox();
            this.numpadGroupBox = new System.Windows.Forms.GroupBox();
            this.button_close_parenthesis = new System.Windows.Forms.Button();
            this.button_open_parenthesis = new System.Windows.Forms.Button();
            this.button_equal = new System.Windows.Forms.Button();
            this.button_minus_plus = new System.Windows.Forms.Button();
            this.button_multiply = new System.Windows.Forms.Button();
            this.button_plus = new System.Windows.Forms.Button();
            this.button_0 = new System.Windows.Forms.Button();
            this.button_comma = new System.Windows.Forms.Button();
            this.button_minus = new System.Windows.Forms.Button();
            this.button_3 = new System.Windows.Forms.Button();
            this.button_2 = new System.Windows.Forms.Button();
            this.button_1 = new System.Windows.Forms.Button();
            this.button_divide = new System.Windows.Forms.Button();
            this.button_6 = new System.Windows.Forms.Button();
            this.button_5 = new System.Windows.Forms.Button();
            this.button_4 = new System.Windows.Forms.Button();
            this.button_sqrt = new System.Windows.Forms.Button();
            this.button_9 = new System.Windows.Forms.Button();
            this.button_8 = new System.Windows.Forms.Button();
            this.button_7 = new System.Windows.Forms.Button();
            this.button_clear = new System.Windows.Forms.Button();
            this.button_exit = new System.Windows.Forms.Button();
            this.numpadGroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // exprTextBox
            // 
            this.exprTextBox.BackColor = System.Drawing.SystemColors.Info;
            resources.ApplyResources(this.exprTextBox, "exprTextBox");
            this.exprTextBox.Name = "exprTextBox";
            // 
            // numpadGroupBox
            // 
            this.numpadGroupBox.Controls.Add(this.button_close_parenthesis);
            this.numpadGroupBox.Controls.Add(this.button_open_parenthesis);
            this.numpadGroupBox.Controls.Add(this.button_equal);
            this.numpadGroupBox.Controls.Add(this.button_minus_plus);
            this.numpadGroupBox.Controls.Add(this.button_multiply);
            this.numpadGroupBox.Controls.Add(this.button_plus);
            this.numpadGroupBox.Controls.Add(this.button_0);
            this.numpadGroupBox.Controls.Add(this.button_comma);
            this.numpadGroupBox.Controls.Add(this.button_minus);
            this.numpadGroupBox.Controls.Add(this.button_3);
            this.numpadGroupBox.Controls.Add(this.button_2);
            this.numpadGroupBox.Controls.Add(this.button_1);
            this.numpadGroupBox.Controls.Add(this.button_divide);
            this.numpadGroupBox.Controls.Add(this.button_6);
            this.numpadGroupBox.Controls.Add(this.button_5);
            this.numpadGroupBox.Controls.Add(this.button_4);
            this.numpadGroupBox.Controls.Add(this.button_sqrt);
            this.numpadGroupBox.Controls.Add(this.button_9);
            this.numpadGroupBox.Controls.Add(this.button_8);
            this.numpadGroupBox.Controls.Add(this.button_7);
            resources.ApplyResources(this.numpadGroupBox, "numpadGroupBox");
            this.numpadGroupBox.Name = "numpadGroupBox";
            this.numpadGroupBox.TabStop = false;
            // 
            // button_close_parenthesis
            // 
            resources.ApplyResources(this.button_close_parenthesis, "button_close_parenthesis");
            this.button_close_parenthesis.Name = "button_close_parenthesis";
            this.button_close_parenthesis.UseVisualStyleBackColor = true;
            this.button_close_parenthesis.Click += new System.EventHandler(this.button_close_parenthesis_Click);
            // 
            // button_open_parenthesis
            // 
            resources.ApplyResources(this.button_open_parenthesis, "button_open_parenthesis");
            this.button_open_parenthesis.Name = "button_open_parenthesis";
            this.button_open_parenthesis.UseVisualStyleBackColor = true;
            this.button_open_parenthesis.Click += new System.EventHandler(this.button_open_parenthesis_Click);
            // 
            // button_equal
            // 
            this.button_equal.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            resources.ApplyResources(this.button_equal, "button_equal");
            this.button_equal.Name = "button_equal";
            this.button_equal.UseVisualStyleBackColor = false;
            this.button_equal.Click += new System.EventHandler(this.button_equal_Click);
            // 
            // button_minus_plus
            // 
            resources.ApplyResources(this.button_minus_plus, "button_minus_plus");
            this.button_minus_plus.Name = "button_minus_plus";
            this.button_minus_plus.UseVisualStyleBackColor = true;
            this.button_minus_plus.Click += new System.EventHandler(this.button_minus_plus_Click);
            // 
            // button_multiply
            // 
            resources.ApplyResources(this.button_multiply, "button_multiply");
            this.button_multiply.Name = "button_multiply";
            this.button_multiply.UseVisualStyleBackColor = true;
            this.button_multiply.Click += new System.EventHandler(this.button_multiply_Click);
            // 
            // button_plus
            // 
            resources.ApplyResources(this.button_plus, "button_plus");
            this.button_plus.Name = "button_plus";
            this.button_plus.UseVisualStyleBackColor = true;
            this.button_plus.Click += new System.EventHandler(this.button_plus_Click);
            // 
            // button_0
            // 
            this.button_0.BackColor = System.Drawing.SystemColors.ButtonFace;
            resources.ApplyResources(this.button_0, "button_0");
            this.button_0.Name = "button_0";
            this.button_0.UseVisualStyleBackColor = false;
            this.button_0.Click += new System.EventHandler(this.button_0_Click);
            // 
            // button_comma
            // 
            resources.ApplyResources(this.button_comma, "button_comma");
            this.button_comma.Name = "button_comma";
            this.button_comma.UseVisualStyleBackColor = true;
            this.button_comma.Click += new System.EventHandler(this.button_comma_Click);
            // 
            // button_minus
            // 
            resources.ApplyResources(this.button_minus, "button_minus");
            this.button_minus.Name = "button_minus";
            this.button_minus.UseVisualStyleBackColor = true;
            this.button_minus.Click += new System.EventHandler(this.button_minus_Click);
            // 
            // button_3
            // 
            this.button_3.BackColor = System.Drawing.SystemColors.ButtonFace;
            resources.ApplyResources(this.button_3, "button_3");
            this.button_3.Name = "button_3";
            this.button_3.UseVisualStyleBackColor = false;
            this.button_3.Click += new System.EventHandler(this.button_3_Click);
            // 
            // button_2
            // 
            this.button_2.BackColor = System.Drawing.SystemColors.ButtonFace;
            resources.ApplyResources(this.button_2, "button_2");
            this.button_2.Name = "button_2";
            this.button_2.UseVisualStyleBackColor = false;
            this.button_2.Click += new System.EventHandler(this.button_2_Click);
            // 
            // button_1
            // 
            this.button_1.BackColor = System.Drawing.SystemColors.ButtonFace;
            resources.ApplyResources(this.button_1, "button_1");
            this.button_1.Name = "button_1";
            this.button_1.UseVisualStyleBackColor = false;
            this.button_1.Click += new System.EventHandler(this.button_1_Click);
            // 
            // button_divide
            // 
            resources.ApplyResources(this.button_divide, "button_divide");
            this.button_divide.Name = "button_divide";
            this.button_divide.UseVisualStyleBackColor = true;
            this.button_divide.Click += new System.EventHandler(this.button_divide_Click);
            // 
            // button_6
            // 
            this.button_6.BackColor = System.Drawing.SystemColors.ButtonFace;
            resources.ApplyResources(this.button_6, "button_6");
            this.button_6.Name = "button_6";
            this.button_6.UseVisualStyleBackColor = false;
            this.button_6.Click += new System.EventHandler(this.button_6_Click);
            // 
            // button_5
            // 
            this.button_5.BackColor = System.Drawing.SystemColors.ButtonFace;
            resources.ApplyResources(this.button_5, "button_5");
            this.button_5.Name = "button_5";
            this.button_5.UseVisualStyleBackColor = false;
            this.button_5.Click += new System.EventHandler(this.button_5_Click);
            // 
            // button_4
            // 
            this.button_4.BackColor = System.Drawing.SystemColors.ButtonFace;
            resources.ApplyResources(this.button_4, "button_4");
            this.button_4.Name = "button_4";
            this.button_4.UseVisualStyleBackColor = false;
            this.button_4.Click += new System.EventHandler(this.button_4_Click);
            // 
            // button_sqrt
            // 
            resources.ApplyResources(this.button_sqrt, "button_sqrt");
            this.button_sqrt.Name = "button_sqrt";
            this.button_sqrt.UseVisualStyleBackColor = true;
            this.button_sqrt.Click += new System.EventHandler(this.button_sqrt_Click);
            // 
            // button_9
            // 
            this.button_9.BackColor = System.Drawing.SystemColors.ButtonFace;
            resources.ApplyResources(this.button_9, "button_9");
            this.button_9.Name = "button_9";
            this.button_9.UseVisualStyleBackColor = false;
            this.button_9.Click += new System.EventHandler(this.button_9_Click);
            // 
            // button_8
            // 
            this.button_8.BackColor = System.Drawing.SystemColors.ButtonFace;
            resources.ApplyResources(this.button_8, "button_8");
            this.button_8.Name = "button_8";
            this.button_8.UseVisualStyleBackColor = false;
            this.button_8.Click += new System.EventHandler(this.button_8_Click);
            // 
            // button_7
            // 
            this.button_7.BackColor = System.Drawing.SystemColors.ButtonFace;
            resources.ApplyResources(this.button_7, "button_7");
            this.button_7.Name = "button_7";
            this.button_7.UseVisualStyleBackColor = false;
            this.button_7.Click += new System.EventHandler(this.button_7_Click);
            // 
            // button_clear
            // 
            this.button_clear.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            resources.ApplyResources(this.button_clear, "button_clear");
            this.button_clear.Name = "button_clear";
            this.button_clear.UseVisualStyleBackColor = false;
            this.button_clear.Click += new System.EventHandler(this.button_clear_Click);
            // 
            // button_exit
            // 
            this.button_exit.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            resources.ApplyResources(this.button_exit, "button_exit");
            this.button_exit.Name = "button_exit";
            this.button_exit.UseVisualStyleBackColor = false;
            this.button_exit.Click += new System.EventHandler(this.button_exit_Click);
            // 
            // calculatorForm
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.button_clear);
            this.Controls.Add(this.button_exit);
            this.Controls.Add(this.numpadGroupBox);
            this.Controls.Add(this.exprTextBox);
            this.Name = "calculatorForm";
            this.numpadGroupBox.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RichTextBox exprTextBox;
        private System.Windows.Forms.GroupBox numpadGroupBox;
        private System.Windows.Forms.Button button_equal;
        private System.Windows.Forms.Button button_minus_plus;
        private System.Windows.Forms.Button button_multiply;
        private System.Windows.Forms.Button button_plus;
        private System.Windows.Forms.Button button_0;
        private System.Windows.Forms.Button button_comma;
        private System.Windows.Forms.Button button_minus;
        private System.Windows.Forms.Button button_3;
        private System.Windows.Forms.Button button_2;
        private System.Windows.Forms.Button button_1;
        private System.Windows.Forms.Button button_divide;
        private System.Windows.Forms.Button button_6;
        private System.Windows.Forms.Button button_5;
        private System.Windows.Forms.Button button_4;
        private System.Windows.Forms.Button button_sqrt;
        private System.Windows.Forms.Button button_9;
        private System.Windows.Forms.Button button_8;
        private System.Windows.Forms.Button button_7;
        private System.Windows.Forms.Button button_clear;
        private System.Windows.Forms.Button button_exit;
        private System.Windows.Forms.Button button_close_parenthesis;
        private System.Windows.Forms.Button button_open_parenthesis;
    }
}

