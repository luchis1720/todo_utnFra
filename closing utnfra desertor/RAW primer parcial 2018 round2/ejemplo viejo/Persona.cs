using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Entidades
{
    public enum Departamentos
    {
        A,
        B,
        C,
        D,
        E,
    }

    public abstract class Persona
    {
        #region Fields
        private string apellido;
        private string documento;
        private string nombre;
        #endregion

        #region Properties
        public string Apellido
        {
            get
            {
                return this.apellido;
            }
        }

        public string Documento
        {
            get
            {
                return this.documento;
            }
            set
            {
                this.documento = value;
            }
        }

        public string Nombre
        {
            get
            {
                return this.nombre;
            }
        }
        #endregion
        
        #region Methods
        public Persona(string nombre, string apellido, string documento)
        {
            this.nombre = nombre;
            this.apellido = apellido;
            this.Documento = documento;
        }

        protected abstract bool ValidarDocumentacion(string doc);

        public virtual string ExponerDatos()
        {
            string retorno;
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat("Apellido: {0}", this.Apellido);
            sb.AppendLine("");
            sb.AppendFormat("Nombre {0}", this.Nombre);
            sb.AppendLine("");
            sb.AppendFormat("Documento: {0}", this.Documento);
            retorno = sb.ToString();
            return retorno;
        }
        #endregion

    }
}
