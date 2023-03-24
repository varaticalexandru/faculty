   /* 
    Licensed under the Apache License, Version 2.0
    
    http://www.apache.org/licenses/LICENSE-2.0
    */
using System;
using System.Xml.Serialization;
using System.Collections.Generic;
namespace Xml2CSharp
{
	[XmlRoot(ElementName="var_rs")]
	public class Var_rs {
		[XmlElement(ElementName="varianta")]
		public List<string> Varianta { get; set; }
	}

	[XmlRoot(ElementName="Intrebare")]
	public class Intrebare {
		[XmlElement(ElementName="idx")]
		public string Idx { get; set; }
		[XmlElement(ElementName="tip")]
		public string Tip { get; set; }
		[XmlElement(ElementName="text")]
		public string Text { get; set; }
		[XmlElement(ElementName="nr_var_rs")]
		public string Nr_var_rs { get; set; }
		[XmlElement(ElementName="var_rs")]
		public Var_rs Var_rs { get; set; }
		[XmlElement(ElementName="linkPoza")]
		public string LinkPoza { get; set; }
		[XmlElement(ElementName="rs_corect")]
		public string Rs_corect { get; set; }
	}

	[XmlRoot(ElementName="TestGrila")]
	public class TestGrila {
		[XmlElement(ElementName="Intrebare")]
		public List<Intrebare> Intrebare { get; set; }
	}

}
