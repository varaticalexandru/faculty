using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace WindowsFormsApp1
{
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void AddNode(XmlNode inXmlNode, TreeNode inTreeNode)
        {
            XmlNode xNode;
            TreeNode tNode;
            XmlNodeList nodeList;

            int i = 0;

            if (inXmlNode.HasChildNodes)
            {
                nodeList = inXmlNode.ChildNodes;
                for (i = 0; i < nodeList.Count; i++)
                {
                    xNode = inXmlNode.ChildNodes[i];
                    inTreeNode.Nodes.Add(new TreeNode(xNode.Name));

                    tNode = inTreeNode.Nodes[i];
                    AddNode(xNode, tNode);
                }
            }
            else
            {
                inTreeNode.Text = inXmlNode.InnerText.ToString();
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            // crearea unui TreeView dintr-un fisier XML

            XmlDocument xmldoc = new XmlDocument();

            XmlNode xmlnode;

            FileStream fs = new FileStream("C:\\Users\\Admin\\Downloads\\contorols.xml", FileMode.Open, FileAccess.Read);

            xmldoc.Load(fs);
            xmlnode = xmldoc.ChildNodes[1];

            treeView1.Nodes.Clear();
            treeView1.Nodes.Add(new TreeNode(xmldoc.DocumentElement.Name));
            TreeNode tNode;
            tNode = treeView1.Nodes[0];

            tNode = treeView1.Nodes[0];
            AddNode(xmlnode, tNode);


        }
    }
}
