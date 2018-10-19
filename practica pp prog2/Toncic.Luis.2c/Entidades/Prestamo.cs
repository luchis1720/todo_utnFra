using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrestamosPersonales
{
    public abstract class Prestamo
    {
        #region CAMPOS

        protected float monto;
        protected DateTime vencimiento;

        #endregion

        #region PROPIEDADES

        public float Monto
        {
            get { return this.monto;}
        }

        public DateTime Vencimiento
        {
            get { return this.vencimiento; }
            set
            {
                if (vencimiento <= DateTime.Now.Date)
                    this.vencimiento = value;
                else
                    this.vencimiento = DateTime.Now.Date;
            }
        }

        #endregion

        #region METODOS 

        public Prestamo(float monto, DateTime vencimiento)
        {
            this.monto = monto;
            this.Vencimiento = vencimiento;
        }

        public abstract void ExtenderPlazo(DateTime nuevoVencimiento);

        public virtual string Mostrar()
        {
            string ans = "";
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat("Monto: {0}, Vencimiento : {1}");
            sb.AppendLine("");

            return ans = sb.ToString();
                       
        }

        public static int OrdenarPorFecha(Prestamo p1, Prestamo p2)
        {
            int ans = 0;

            if (p1.Vencimiento < p2.Vencimiento)
                ans = 1;
            else if (p1.Vencimiento > p2.Vencimiento)
                ans = -1;
                        
            return ans;
        }

        

        #endregion
    }
}
