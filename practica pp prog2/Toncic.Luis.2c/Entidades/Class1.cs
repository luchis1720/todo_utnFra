using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrestamosPersonales
{
    public class Lib
    {
        public enum PeriocidadDePagos
        {
            Mensual=25,
            Bimestral=35,
            Trimestral=40
        }

        public enum TipoDeprestamo
        {
            Pesos,
            Dolares,
            Todos
        }
    }
}
