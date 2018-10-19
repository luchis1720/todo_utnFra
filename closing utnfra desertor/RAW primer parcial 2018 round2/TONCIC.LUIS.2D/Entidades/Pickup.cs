using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class PickUp : Vehiculo
    {
        #region Fields

        private string modelo;
        private int valorHora;

        #endregion

        #region Methods

        public PickUp(string patente, string modelo) : base (patente)
        {
            this.modelo = modelo;
        }

        public PickUp(string patente, string modelo, int valorHora) : this(patente, modelo)
        {
            this.valorHora = 70;
        }

        public override string ConsultarDatos()
        {
            string ans;
            StringBuilder sb = new StringBuilder(); 

            sb.AppendFormat(Patente.ToString());
            sb.AppendLine("");
            sb.AppendFormat("Modelo: {0}", this.modelo);
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
