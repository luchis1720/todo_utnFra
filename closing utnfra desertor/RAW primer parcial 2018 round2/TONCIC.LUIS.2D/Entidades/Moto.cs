using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Moto : Vehiculo
    {
        #region Fields 

        private int cilindrada;
        private short ruedas;
        private int valorHora;

        #endregion

        #region Methods

        public Moto(string patente, int cilindradas) : base (patente)
        {
            this.cilindrada = cilindradas;
            this.ruedas = 2;
        }

        public Moto(string patente, int cilindradas, short ruedas) : this(patente, cilindradas)
        {
            this.ruedas = ruedas;
        }

        public Moto(string patente, int cilindradas, short ruedas, int valorHora) : this(patente, cilindradas, ruedas)
        {
            this.valorHora = 30;
        }

        public override string ConsultarDatos()
        {
            string ans;
            StringBuilder sb = new StringBuilder(); 

            sb.AppendFormat(Patente.ToString());
            sb.AppendLine("");
            sb.AppendFormat("Cilindrada: {0}", this.cilindrada);
            sb.AppendLine("");
            sb.AppendFormat("Ruedas: {0}", this.ruedas);
            sb.AppendLine("");
            
            ans = sb.ToString();
            return ans;
        }

        public string ImprimirTicket()
        {
            string ans;
            int estadia = (DateTime.Now.Date - ingreso) * valorHora; //parsear
            StringBuilder sb = new StringBuilder();

            sb.AppendLine(base.ImprimirTicket());
            sb.AppendLine(this.ConsultarDatos());
            sb.AppendLine("");

            sb.AppendFormat("costo estadia: {0} ", estadia);

            ans = sb.ToString();
            return ans;
        }

        #endregion


    }
}
