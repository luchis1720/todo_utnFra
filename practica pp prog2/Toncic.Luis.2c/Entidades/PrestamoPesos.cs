using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrestamosPersonales
{
   public class PrestamoPesos : Prestamo
    {
        #region CAMPOS

        private float porcentajeInteres;

        #endregion

        #region PROPIEDADES

        public float Interes
        {
            get { return this.CalcularInteres(); }
        }

        #endregion

        #region METODOS

        public PrestamoPesos(float monto, DateTime vencimiento, float interes)
            : base(monto, vencimiento)
        {
             this.porcentajeInteres = interes;
        }

        public PrestamoPesos(Prestamo prestamo, float porcentajeInteres)
            : base(prestamo.Monto, prestamo.Vencimiento)
        {
            this.porcentajeInteres = porcentajeInteres ;
        }

        private float CalcularInteres()
        {
            float ans=0;

            ans = (this.porcentajeInteres * this.Monto) / 100;
            ans += this.Monto;  

            return ans;
        }

        public override void ExtenderPlazo(DateTime nuevoVencimiento)
        {
            double dias;
            dias = nuevoVencimiento.Subtract(this.Vencimiento).TotalDays;
            dias = (int)dias * 0.25f;
            this.porcentajeInteres += (float)dias;
            this.Vencimiento = nuevoVencimiento;
        }

        public override string Mostrar()
        {
            string retorno;
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat("{0} Interes: {1}", base.Mostrar(), this.Interes);
            retorno = sb.ToString();
            return retorno;
        }



        #endregion
    }
}
