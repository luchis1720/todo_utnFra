using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Entidades
{
    public class Jefe : Persona
    {
        #region Fields
        private DateTime fechaIngreso;
        #endregion

        #region Properties
        public int Antiguedad
        {
            get
            {
                double dias;
                dias = DateTime.Now.Subtract(this.fechaIngreso).TotalDays;
                return (int)dias;
            }
        }
        #endregion

        #region Methods
        public Jefe(string nombre, string apellido, string documento)
        :base(nombre,apellido,documento)
        {
        }

        public Jefe(string nombre, string apellido, string documento, DateTime fechaIngreso)
            : this(nombre, apellido, documento)
        {
            this.fechaIngreso = fechaIngreso;
        }

        public override string ExponerDatos()
        {
            string retorno;
            StringBuilder sb = new StringBuilder();
            sb.AppendLine(base.ExponerDatos());
            sb.AppendFormat("Dias de antiguedad: {0}", this.Antiguedad);
            retorno = sb.ToString();
            return retorno;
        }

        protected override bool ValidarDocumentacion(string doc)
        {
            throw new NotImplementedException();
        }
        #endregion
    }
}
