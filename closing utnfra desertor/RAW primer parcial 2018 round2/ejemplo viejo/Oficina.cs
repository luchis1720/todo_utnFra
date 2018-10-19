using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Entidades
{
    public class Oficina
    {
        #region Fields
        private Departamentos departamento;
        private List<Empleado> empleados;
        private Jefe jefe;
        private short piso;
        #endregion

        #region Properties
        public string PisoDivision
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
        private Oficina()
        {
            empleados = new List<Empleado>();
        }

        public Oficina(short piso, Departamentos departamento, Jefe jefe)
            :this()
        {
            this.piso = piso;
            this.departamento = departamento;
            this.jefe = jefe;
        }

        public static bool operator ==(Oficina o, Empleado e)
        {
            foreach (Empleado aux in o.empleados)
            {
                if (object.Equals(aux,e))
                {
                    return true;
                }
            }
            return false;
        }

        public static bool operator !=(Oficina o, Empleado e)
        {
            if (!(o == e))
            {
                return true;
            }
            return false;
        }

        public static Oficina operator +(Oficina o, Empleado e)
        {
            if (o != e)
            {
                if (o.PisoDivision == e.PisoDepartamento)
                {
                    o.empleados.Add(e);
                    return o;
                }
            }
            
            return o;
        }

        public static explicit operator string(Oficina o)
        {
            string retorno;
            StringBuilder sb = new StringBuilder();
            sb.AppendLine(o.PisoDivision);
            sb.AppendFormat("Jefe: {0}", o.jefe.ExponerDatos());
            sb.AppendLine("");
            sb.AppendLine("Empleados");
            foreach (Empleado aux in o.empleados)
            {
                sb.AppendLine(aux.ExponerDatos());
            }
            retorno = sb.ToString();
            return retorno;
        }
        #endregion
    }
}
