using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PrestamosPersonales;

namespace EntidadFinanciera
{
    public class Financiera
    {
        private List<Prestamo> listaPrestamos;
        private string razonSocial;

		  


        public List<Prestamo> ListaPrestamos
        {
            get
            {
                return this.listaPrestamos;
            }
        }

        public string RazonSocial
        {
            get
            {
                return this.razonSocial;
            }
        }

        public float InteresesEnDolares
        {
            get 
            {
                return this.CalcularInteresGanado(TipoDePrestamo.Dolares);
            }
        }

        public float InteresesEnPesos
        {
            get
            {
                return this.CalcularInteresGanado(TipoDePrestamo.Pesos);
            }
        }

        public float InteresesTotales
        {
            get
            {
                return this.CalcularInteresGanado(TipoDePrestamo.Todos);
            }
        }

        private Financiera()
        {
            listaPrestamos = new List<Prestamo>();
        }

        public Financiera(string razonSocial)
            :this()
        {
            this.razonSocial = razonSocial;
        }


        private float CalcularInteresGanado(TipoDePrestamo prestamo)
        {
            float retorno = 0;
            float retornoDolar = 0;
            float retornoPeso = 0;
            PrestamoDolar auxDolar;
            PrestamoPesos auxPeso;
            foreach (Prestamo aux in this.listaPrestamos)
            {
                if (aux is PrestamoDolar)
                {
                    auxDolar = (PrestamoDolar)aux;
                    retornoDolar += auxDolar.Interes;
                }
                else
                {
                    auxPeso = (PrestamoPesos)aux;
                    retornoPeso += auxPeso.Interes;
                }
            }
            switch (prestamo)
            { 
                case TipoDePrestamo.Dolares:
                    retorno = retornoDolar;
                    break;
                case TipoDePrestamo.Pesos:
                    retorno = retornoPeso;
                    break;
                case TipoDePrestamo.Todos:
                    retorno = retornoDolar + retornoPeso;
                    break;
            }
            return retorno;
        }

        public static bool operator ==(Financiera financiera, Prestamo prestamo)
        {
            bool retorno = false;
            foreach (Prestamo aux in financiera.ListaPrestamos)
            {
                if (object.Equals(aux, prestamo))
                {
                    retorno = true;
                }
            }
            return retorno;
        }

        public static bool operator !=(Financiera financiera, Prestamo prestamo)
        {
            bool retorno = false;
            if (!(financiera == prestamo))
                retorno = true;
            return retorno;
        }

        public static Financiera operator +(Financiera financiera, Prestamo prestamo)
        {            
                if (financiera == prestamo)
                {
                    return financiera;
                }
            
            financiera.ListaPrestamos.Add(prestamo);
            return financiera;
        }

        public void OrdenarPrestamos()
        {
            this.ListaPrestamos.Sort(Prestamo.OrdenarPorFecha);
        }


        public static explicit operator string(Financiera financiera)
        {
            StringBuilder sb = new StringBuilder();
            foreach (Prestamo aux in financiera.ListaPrestamos)
            {
                sb.AppendFormat("{0}", aux.Mostrar());
                sb.AppendLine("");
            }
            return sb.ToString();
        }

        public static string Mostrar(Financiera financiera)
        {
            //string(financiera);
            string retorno = (string)financiera;
            return retorno;
        }


    }
}
