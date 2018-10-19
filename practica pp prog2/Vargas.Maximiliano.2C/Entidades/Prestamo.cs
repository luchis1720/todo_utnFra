using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrestamosPersonales
{
    public enum PeriodicidadDePagos
    {
        Mensual,
        Bimestral,
        Trimestral,
    }

    public enum TipoDePrestamo
    {
        Pesos,
        Dolares,
        Todos,
    }

    public abstract class Prestamo
    {
        protected float monto;
        protected DateTime vencimiento;

        public float Monto
        {
            get
            {
                return this.monto;
            }
        }

        public DateTime Vencimiento
        {
            set
            {
                if (vencimiento <= DateTime.Now.Date)
                    this.vencimiento = value;
                else
                    this.vencimiento = DateTime.Now.Date;
            }
            get
            {
                return this.vencimiento;
            }
        }

        public abstract void ExtenderPlazo(DateTime nuevoVencimiento);

        public virtual string Mostrar()
        {
            string retorno = "";
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat("Monto: {0} Vencimiento : {1}", this.Monto, this.Vencimiento.Date.ToString("MM/dd/yyyy"));
            retorno = sb.ToString();
            return retorno;
        }

        public static int OrdenarPorFecha(Prestamo prestamo1, Prestamo prestamo2)
        {
            int retorno = 0;

            if (prestamo1.Vencimiento <= prestamo2.Vencimiento)
                retorno = 1;
            else if (prestamo2.Vencimiento <= prestamo1.Vencimiento)
                retorno = -1;

            return retorno;
        }

        public Prestamo(float monto, DateTime vencimiento)
        {
            this.monto = monto;
            this.Vencimiento = vencimiento;
        }
    }
}
