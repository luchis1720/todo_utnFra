using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Entidades
{
    public class Empleado : Persona
    {
        #region Fields
        private Departamentos departamento;
        private short piso;
        #endregion

        #region Properties
        public string PisoDepartamento
        {
            get
            {
                string retorno;
                StringBuilder sb = new StringBuilder();
                sb.AppendFormat("{0}º{1}", departamento.ToString(), piso.ToString());
                retorno = sb.ToString();
                return retorno;
            }
        }
        #endregion

        #region Methods
        public Empleado(string nombre, string apellido, string documento, short piso, Departamentos departamento)
            : base(nombre, apellido, documento)
        {
            this.departamento = departamento;
            this.piso = piso;
        }

        public override string ExponerDatos()
        {
            string retorno;
            StringBuilder sb = new StringBuilder();
            sb.Append(base.ExponerDatos());
            sb.AppendLine("");
            sb.AppendFormat("Piso/Departamento: {0}", this.PisoDepartamento);
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
