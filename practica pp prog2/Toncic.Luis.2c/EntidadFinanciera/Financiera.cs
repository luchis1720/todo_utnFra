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
        #region CAMPOS

        private List<Prestamo> listaDePrestamos;
        private string razonSocial;
        
        #endregion

        #region PROPIEDADES

        public float InteresesEnDolares
        {
            get { return this.CalcularInteresGanado(PrestamosPersonales.Lib.TipoDeprestamo.Dolares); }
        }

        public float InteresesEnPesos
        {
            get { return this.CalcularInteresGanado(PrestamosPersonales.Lib.TipoDeprestamo.Pesos); }
        }

        public float InteresesTotales
        {
            get { return this.CalcularInteresGanado(PrestamosPersonales.Lib.TipoDeprestamo.Todos); }
        }

        public List<Prestamo> ListaDePrestamos
        {
            get { return this.listaDePrestamos; }
        }

        public string RazonSocial
        {
            get { return this.razonSocial; }
        }
        
        #endregion

        #region METODOS

        private Financiera()
        {
            listaDePrestamos = new List<Prestamo>(); 
        }

        public Financiera(string razonSocial) 
            : this() 
        {
            this.razonSocial = razonSocial;
        }

        private float CalcularInteresGanado(PrestamosPersonales.Lib.TipoDeprestamo prestamo)
        {
            float retorno = 0;
            float retornoDolar = 0;
            float retornoPeso = 0;
            PrestamoDolar auxDolar;
            PrestamoPesos auxPeso;
            foreach (Prestamo aux in this.ListaDePrestamos)
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
                case PrestamosPersonales.Lib.TipoDeprestamo.Dolares:
                    retorno = retornoDolar;
                    break;
                case PrestamosPersonales.Lib.TipoDeprestamo.Pesos:
                    retorno = retornoPeso;
                    break;
                case PrestamosPersonales.Lib.TipoDeprestamo.Todos:
                    retorno = retornoDolar + retornoPeso;
                    break;
            }
            return retorno;
        }
                              
        private void AgregarPrestamo(Prestamo nuevoPrestamo)
        {
            this.listaDePrestamos.Add(nuevoPrestamo);
        }

        public void OrdenarPrestamos()
        {
            this.ListaDePrestamos.Sort(Prestamo.OrdenarPorFecha);
        }


        public static explicit operator string(Financiera financiera)
        {
            StringBuilder sb = new StringBuilder();
            foreach (Prestamo aux in financiera.listaDePrestamos)
            {
                sb.AppendFormat("{0}", aux.Mostrar());
                sb.AppendLine("");
            }
            return sb.ToString();
        }

        public static string Mostrar(Financiera financiera)
        {
            string retorno = (string)financiera;
            return retorno;
        }

        #endregion

        #region OPERADORES

        public static bool operator ==(Financiera financiera, Prestamo prestamo)
        {
            bool ans = false;

            foreach (Prestamo aux in financiera.listaDePrestamos)
            {
                if (aux == prestamo)
                {
                    ans = true;
                    break;
                }
            }

            return ans;
        }

        public static bool operator !=(Financiera financiera, Prestamo prestamo)
        {
            bool ans = false;

            if (!(financiera == prestamo))
                ans = true;

            return ans;
        }

        public static Financiera operator +(Financiera financiera, Prestamo prestamoNuevo)
        {

            if (prestamoNuevo == financiera)
                return financiera;

            financiera.AgregarPrestamo(prestamoNuevo);
            return financiera;
        }


        #endregion
                
    }
}
