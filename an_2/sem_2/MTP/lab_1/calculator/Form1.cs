using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Z.Expressions;

namespace calculator
{
    public partial class calculatorForm : Form
    {
        public calculatorForm()
        {
            InitializeComponent();
        }

        private void button_7_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += "7";
        }

        private void button_8_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += "8";
        }

        private void button_9_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += "9";
        }

        private void button_4_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += "4";
        }

        private void button_5_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += "5";
        }

        private void button_6_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += "6";
        }

        private void button_1_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += "1";
        }

        private void button_2_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += "2";
        }

        private void button_3_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += "3";
        }

        private void button_0_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += "0";
        }

        private void button_plus_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += "+";
        }

        private void button_minus_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += "-";
        }

        private void button_divide_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += "/";
        }

        private void button_sqrt_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += "Sqrt";
        }

        private void button_multiply_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += "*";
        }

        private void button_equal_Click(object sender, EventArgs e)
        {
            // evaluate expression and write it on exprTextBox
            String expr = exprTextBox.Text;

            try
            {
                float result = Eval.Execute<float>(expr);

                exprTextBox.Text = Convert.ToString(result);
            }
            catch (Exception)
            {
                MessageBox.Show("Operatie eronata !", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }

        private void button_comma_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += ".";
        }

        private void button_minus_plus_Click(object sender, EventArgs e)
        {
            String expr = exprTextBox.Text;
            String expr_ = "";

            int idx_plus = expr.LastIndexOf("+");   // last occurence of "+" in the expression string
            int idx_minus = expr.LastIndexOf("-");  // last occurence of "-" in the expression string

            // if last "+" is ahead of last "-" in the expression string
            if (idx_plus > idx_minus)
            {
                expr_ = expr.Substring(0, idx_plus) + "-" + expr.Substring(idx_plus + 1);
            }
            else // if (idx_minus > idx_plus)
            {
                expr_ = expr.Substring(0, idx_minus) + "+" + expr.Substring(idx_minus + 1);
            }

            exprTextBox.Text = expr_;
        }

        private void button_exit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button_clear_Click(object sender, EventArgs e)
        {
            exprTextBox.Text = "";
        }

        private void button_open_parenthesis_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += "(";
        }

        private void button_close_parenthesis_Click(object sender, EventArgs e)
        {
            exprTextBox.Text += ")";
        }


    }
}
