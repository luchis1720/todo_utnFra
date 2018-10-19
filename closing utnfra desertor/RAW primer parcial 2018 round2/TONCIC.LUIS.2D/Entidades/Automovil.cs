using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Automovil : Vehiculo
    {
        #region Fields

        private ConsoleColor color;
        private int valorHora;

        #endregion
        
        #region Methods

        public Automovil (string patente, ConsoleColor color) : base (patente)
        {
            this.color = color;
        }

        public Automovil (string patente, ConsoleColor color, int valorHora) : this (patente, color)
        {
            this.valorHora = 50;
        }

        public override string ConsultarDatos()
        {
            string ans;
            StringBuilder sb = new StringBuilder(); 

            sb.AppendFormat(Patente.ToString());
            sb.AppendLine("");
            sb.AppendFormat("Color: {0}", this.color);
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
