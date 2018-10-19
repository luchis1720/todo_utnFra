using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrestamosPersonales
{
    public class PrestamoDolar : Prestamo
    {
        PeriodicidadDePagos periodicidad;

        public float Interes
        {
            get
            {
                return this.CalcularInteres();
            }
        }

        public PeriodicidadDePagos Periodicidad
        {
            get
            {
                return this.periodicidad;
            }
        }

        private float CalcularInteres()
        {
            float retorno = 0;
            switch (Periodicidad)
            {
                case PeriodicidadDePagos.Mensual:
                    retorno = (25 * this.Monto) / 100;
                    retorno += this.Monto;
                    break;
                case PeriodicidadDePagos.Bimestral:
                    retorno = (35 * this.Monto) / 100;
                    retorno += this.Monto;
                    break;
                case PeriodicidadDePagos.Trimestral:
                    retorno = (40 * this.Monto) / 100;
                    retorno += this.Monto;
                    break;
            }

            return retorno;
        }

        public override void ExtenderPlazo(DateTime nuevoVencimiento)
        {
            double dias;
            dias = nuevoVencimiento.Subtract(this.Vencimiento).TotalDays;
            dias =  (int)dias * 2.5;
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

        public PrestamoDolar(float monto, DateTime vencimiento, PeriodicidadDePagos periodicidad)
            :base(monto,vencimiento)
        {
            this.periodicidad = periodicidad;
        }
        public PrestamoDolar(Prestamo prestamo, PeriodicidadDePagos periodicidad)
        :base(prestamo.Monto,prestamo.Vencimiento)
        {
            this.periodicidad = periodicidad;
        }
    }
}
