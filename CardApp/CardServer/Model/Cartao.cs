using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Web;

namespace CardServer.Model
{
    [DataContract]
    public class Cartao
    {
        [DataMember] public string Numero { get; set; }
        [DataMember] public string Bandeira { get; set; }
        [DataMember] public DateTime Validade { get; set; }
        [DataMember] public string Nome { get; set; }
        [DataMember] public string NumSeguranca { get; set; }
        [DataMember] public double Limite { get; set; }
        [DataMember] public double Gasto { get; set; }
    }
}