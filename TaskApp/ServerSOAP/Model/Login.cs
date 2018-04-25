using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Web;

namespace ServerSOAP.Model
{
    [DataContract]
    public class Login
    {
        [DataMember]public string username { get; set; }
        [DataMember]public string password { get; set; }
    }
}