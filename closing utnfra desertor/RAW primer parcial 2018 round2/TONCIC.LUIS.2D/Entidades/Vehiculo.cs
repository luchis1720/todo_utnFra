using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public abstract class Vehiculo
    {
        #region Fields

        protected DateTime ingreso;
        private string patente;

        #endregion


        #region Properties

        public string Patente
        {
            get
            {
                return this.patente;   
            }
            set
            {
                if (value.Length == 5)
                {
                    this.patente = value;
                }
            }
        }

        #endregion


        #region Methods

        public Vehiculo(string patente)
        {
            this.ingreso = DateTime.Now.AddHours(-3);
            this.Patente = patente;        }

        public abstract string ConsultarDatos();

        public virtual string ImprimirTicket()
        {
            string ans;
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat(Patente.ToString());
            sb.AppendLine("");
            sb.AppendFormat("Hora ingreso: {0} ", ingreso);


            ans = sb.ToString();
            return ans;

        }

        public static bool operator ==(Vehiculo v1, Vehiculo v2)
        {
            bool ans = false;
            if(v1.Patente==v2.Patente && (v1 typeof(v2)) ) //WHAT
            {
                ans = true;
            }
            return ans;
        }

        public static bool operator !=(Vehiculo v1, Vehiculo v2)
        {
            return !(v1==v2);
        }

        public string ToString()
        {
            return string.Format("Patente {0}", Patente);
        }
     
        #endregion
    }
}
