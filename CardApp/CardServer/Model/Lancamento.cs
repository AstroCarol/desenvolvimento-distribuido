using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Web;

namespace CardServer.Model
{
    [DataContract]
    public class Lancamento
    {
        [DataMember] public string Empresa { get; set; }
        [DataMember] public double Valor { get; set; }
        [DataMember] public DateTime Data { get; set; }
        [DataMember] public int NumParcelas { get; set; }
    }
}