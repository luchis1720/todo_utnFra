using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrestamosPersonales
{
    public class PrestamoPesos : Prestamo
    {
        private float porcentajes;

        public float Interes
        {
            get
            {
                return this.CalcularInteres();
            }
        }

        private float CalcularInteres()
        {
            float retorno;

            retorno = (this.porcentajes * this.Monto) / 100;
            retorno += this.Monto;

            return retorno;
        }

        public override void  ExtenderPlazo(DateTime nuevoVencimiento)
        {
            double dias;
            dias = nuevoVencimiento.Subtract(this.Vencimiento).TotalDays;
            dias = (int)dias * 0.25f;
            this.porcentajes += (float)dias;
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

        public PrestamoPesos(float monto, DateTime vencimiento, float porcentajeInteres)
        :base(monto,vencimiento)
        {
            this.porcentajes = porcentajeInteres;
        }
        public PrestamoPesos(Prestamo prestamo, float porcentajeInteres)
            : base(prestamo.Monto, prestamo.Vencimiento)
        {
            this.porcentajes = porcentajeInteres;
        }
    }
}
