using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Laboratory2 {
    public abstract class State : IState {

        #region Private Fields

        /// <summary>
        /// Minimalna gwarantowana wygrana dla gracza maksymalizującego.
        /// </summary>
        private double alpha = double.NegativeInfinity;

        /// <summary>
        /// Maksymalna gwarantowana wygrana dla gracza minimalizującego.
        /// </summary>
        private double beta = Double.PositiveInfinity;

        #endregion //end Private Fields

        #region Protected Fields

        /// <summary>
        /// Dzieci
        /// </summary>
        protected List<IState> children = null;

        /// <summary>
        /// Głębokość stanu w drzewie
        /// </summary>
        protected double depth = 0.0;

        /// <summary>
        /// Koszt osiągnięcia bierzącego stanu ze stanu początkowego
        /// </summary>
        protected double g = 0.0;

        /// <summary>
        /// Ocena heurystyczna
        /// </summary>
        protected double h = 0.0;

        /// <summary>
        /// Definiuje czy wybrany stan jest dostępnu. W grach jak sudoku wybrany stan może być nie osiągalny.
        /// </summary>
        protected bool isAdmissible;

        /// <summary>
        /// Rodzic
        /// </summary>
        protected IState parent = null;

        /// <summary>
        /// Zwraca lub ustawia zazwę początkowego ruchu pozwalającego na dojście do tego stanu.
        /// </summary>
        protected String rootMove = null;

        #endregion //end Protected Fields

        #region Constructors

        /// <summary>
        /// Konstuktor tworzący nową instancje.
        /// </summary>
        /// <param name="parent">Rodzic stanu.</param>
        public State() {
            this.children = new List<IState>();
        }

        /// <summary>
        /// Konstuktor tworzący nową instancje.
        /// </summary>
        /// <param name="parent">Rodzic stanu.</param>
        public State(IState parent) : this() {
            this.parent = parent;
            this.parent.Children.Add(this);
        }

        #endregion //end Constructors

        #region IState Members

        #region Properties

        /// <summary>
        /// Minimalna gwarantowana wygrana dla gracza maksymalizującego.
        /// </summary>
        public double Alpha {
            get {
                return this.alpha;
            }
            set {
                this.alpha = value;
            }
        }

        /// <summary>
        /// Maksymalna gwarantowana wygrana dla gracza minimalizującego.
        /// </summary>
        public double Beta {
            get {
                return this.beta;
            }
            set {
                this.beta = value;
            }
        }

        /// <summary>
        /// Zwraca i ustawia potomków danego stanu.
        /// </summary>
        public List<IState> Children {
            get {
                return this.children;
            }
            set {
                this.children = value;
            }
        }

        /// <summary>
        /// Zwraca lub ustawia głębokość stanu w drzwie.
        /// </summary>
        public double Depth {
            get {
                return this.depth;
            }
            set {
                this.depth = value;
            }
        }

        /// <summary>
        /// Zwraca f. f = g + h.
        /// </summary>
        public double F {
            get {
                return this.g + this.h;
            }
        }

        /// <summary>
        /// Zwraca i ustawia g - koszt osiągnięca wybranego stanu.
        /// </summary>
        public double G {
            get {
                return this.g;
            }
            set {
                this.g = value;
            }
        }

        /// <summary>
        /// Zwraca h - heurystyczną wartość dla stanu
        /// </summary>
        public double H {
            get {
                return this.h;
            }
            set {
                this.h = value;
            }
        }

        /// <summary>
        /// Nazwa statnu jednoznacznie go identyfikująca. 
        /// </summary>
        public abstract string ID {
            get;
        }

        /// <summary>
        /// Definiuje czy wybrany stan jest dostępnu. W grach jak sudoku wybrany stan może być nie osiągalny.
        /// </summary>
        public bool IsAdmissible {
            get { return this.isAdmissible; }
        }

        /// <summary>
        /// Zwraca i ustawia przodka danego stanu.
        /// </summary>
        public IState Parent {
            get {
                return this.parent;
            }
            set {
                this.parent = value;
            }
        }

        /// <summary>
        /// Zwraca lub ustawia zazwę początkowego ruchu pozwalającego na dojście do tego stanu.
        /// </summary>
        public string RootMove {
            get {
                return this.rootMove;
            }
            set {
                this.rootMove = value;
            }
        }

        #endregion //end Properties

        #region Methods

        /// <summary>
        /// Oblicza h - heurystyczną wartość dla danego stanu.
        /// </summary>
        /// <returns>Heurystyczna wartość.</returns>
        public abstract double ComputeHeuristicGrade();

        #endregion //end Methods

        #endregion //end IState Members

        #region IComparable<IState> Members

        /// <summary>
        /// Implementacja motody CompareTo.
        /// </summary>
        /// <param name="other">Stan do którego porównujemy stan bierzący.</param>
        /// <returns>Jeżeli wartość funkcji heurystycznej bieżacego stanu jest mniejsza lub równa do 
        /// stanu porównywanego to -1 jeżeli większa to 1.</returns>
        /// <remarks>Porównywanie nie przyjmuj stanu 0 aby można była szeregować stany w kolekcjach typu: SortedDictionary, SortedList.</remarks>
        public int CompareTo(IState other) {
            return this.F <= other.F ? -1 : 1;
        }

        #endregion
    }
}
