using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrestamosPersonales
{
   public class PrestamoDolar : Prestamo
    {
        #region CAMPOS

        private Lib.PeriocidadDePagos periocidad;

        #endregion

        #region PROPIEDADES

        public float Interes
        {
            get { return this.CalcularInteres(); }
        }

        public Lib.PeriocidadDePagos Periocidad
        {
            get { return this.periocidad; }
        }

        #endregion

        #region METODOS

        public PrestamoDolar(float monto, DateTime vencimiento, Lib.PeriocidadDePagos periocidad)
            : base(monto, vencimiento)
        {
             this.periocidad = periocidad;
        }

        public PrestamoDolar(Prestamo prestamo, Lib.PeriocidadDePagos periocidad)
            : base(prestamo.Monto, prestamo.Vencimiento)
        {
            this.periocidad = periocidad;
        }

        private float CalcularInteres()
        {
            float ans = 0;

            switch (Periocidad)
            {
                case Lib.PeriocidadDePagos.Mensual:
                    ans = (25 * this.Monto) / 100;
                    ans += this.Monto;
                    break;
                case Lib.PeriocidadDePagos.Bimestral:
                    ans = (35 * this.Monto) / 100;
                    ans += this.Monto;
                    break;
                case Lib.PeriocidadDePagos.Trimestral:
                    ans = (40 * this.Monto) / 100;
                    ans += this.Monto;
                    break;
            }
            

            return ans;
        }

        public override void ExtenderPlazo(DateTime nuevoVencimiento)
        {
            double dias;
            dias = nuevoVencimiento.Subtract(this.Vencimiento).TotalDays;
            dias = (int)dias * 2.5;
            this.monto += (float)dias;
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
