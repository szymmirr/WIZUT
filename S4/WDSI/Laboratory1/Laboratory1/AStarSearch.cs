using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Laboratory1 {
    public abstract class AStarSearch {

        #region Protected Fields

        /// <summary>
        /// Zbiór Closed - sortowany słownik hashów stanów i samych stanów.
        /// </summary>
        protected Dictionary<string, IState> closed = null;

        /// <summary>
        /// Stan początkowy.
        /// </summary>
        protected IState initialState = null;

        /// <summary>
        /// Decyduje czy zatrzymać algorytm po odnalezieniu pierwszego rozwiązania.
        /// </summary>
        protected bool isStopAfterFirstSolution = true;

        /// <summary>
        /// Decyduje czy zatrzymać algorytm po odnalezieniu drugiego rozwiązania.
        /// </summary>
        protected bool isStopAfterSecondSolution = true;

        /// <summary>
        /// Zbiór Open - stany które mają zostać odwiedzone. Pozwala na sprawne pobranie pierwszego elementu z listy i usunięcie go
        /// odwołując się do indeksu.
        /// .NET nie posiada kolejki priorytetowej. Można by użyć kolekcji SortedSet ale ona nie pozwala na usunięcie elementu 
        /// spod danego indeksu. Jeżeli kiedyś się dorobi takie funkcji to pola open i open2 będzie można połączyć w jedno.
        /// </summary>
        protected SortedList<IState, string> open = null;

        /// <summary>
        /// Druga część zbioru open. Pozwala on na szybkie sprawdzenie czy dane stan został już dodany ( O(1) ) 
        /// .NET nie posiada kolejki priorytetowej. Można by użyć kolekcji SortedSet ale ona nie pozwala na usunięcie elementu 
        /// spod danego indeksu. Jeżeli kiedyś się dorobi takie funkcji to pola open i open2 będzie można połączyć w jedno.
        /// </summary>
        protected HashSet<string> open2 = null;

        /// <summary>
        /// Lista odnalezionych rozwiązań.
        /// </summary>
        protected List<IState> solutions = null;

        #endregion //end Protected Fields

        #region Properties

        /// <summary>
        /// Zbiór Closed - sortowany słownik hashów stanów i samych stanów, które zostały już dowiedzone.
        /// </summary>
        public Dictionary<string, IState> Closed {
            get { return this.closed; }
        }

        /// <summary>
        /// Zbiór Open - stany które mają zostać odwiedzone.
        /// </summary>
        public SortedList<IState, string> Open {
            get { return this.open; }
        }

        /// <summary>
        /// Lista odnalezionych rozwiązań.
        /// </summary>
        public List<IState> Solutions {
            get {
                return this.solutions;
            }
        }

        #endregion //end Properties

        #region Constructors

        /// <summary>
        /// Konstruktor.
        /// </summary>
        /// <param name="initialState">Stan początkowy.</param>
        /// <param name="isStopAfterFirstSolution">Decyduje czy zatrzymać algorytm po odnalezieniu pierwszego rozwiązania.</param>
        /// <param name="isStopAfterSecondSolution">Decyduje czy zatrzymać algorytm po odnalezieniu drugiego rozwiązania.</param>
        public AStarSearch(IState initialState, bool isStopAfterFirstSolution, bool isStopAfterSecondSolution) {
            this.closed = new Dictionary<string, IState>();

            this.initialState = initialState;
            this.isStopAfterFirstSolution = isStopAfterFirstSolution;
            this.isStopAfterSecondSolution = isStopAfterSecondSolution;
            this.solutions = new List<IState>();

            this.open = new SortedList<IState, string>();
            this.open2 = new HashSet<string>();
        }

        #endregion //end Constructors

        #region Protected Methods

        /// <summary>
        /// Metoda powinna zawierać wszelkie niezbędne operacje do zbudowania stanów potomnych.
        /// </summary>
        /// <param name="parent">Stan rodzica.</param>
        protected abstract void buildChildren(IState parent);

        /// <summary>
        /// Zwraca wartość bool mówiąco czy stan podany w parametrze jest rozwiązaniem.
        /// </summary>
        /// <param name="state">Stan do sprawdzenia.</param>
        /// <returns>Wartość bool czy stan jest rozwiązaniem.</returns>
        protected abstract bool isSolution(IState state);

        /// <summary>
        /// Zarejestrowanie rozwiązania. Poprzez przeciązenie metody można do niej dodać więcej akcji.
        /// </summary>
        /// <param name="solutionState">Stan rozwiązania.</param>
        protected void registerSolution(IState solutionState) {
            solutions.Add(solutionState);
        }

        #endregion //end Private Methods

        #region Public Methods

        /// <summary>
        /// Wykonanie algorytmu A*.
        /// </summary>
        public void DoSearch() {
            IState currentState = this.initialState;
            while (true) {
                bool isSol = isSolution(currentState);
                if (isSol) {
                    registerSolution(currentState);

                    if (this.isStopAfterFirstSolution) {
                        break;
                    }

                    if ((solutions.Count == 2) && (this.isStopAfterSecondSolution)) {
                        break;
                    }
                }
                else {
                    buildChildren(currentState);

                    foreach (IState child in currentState.Children) {

                        if (this.closed.ContainsKey(child.ID)) {
                            continue;
                        }

                        if (!this.open2.Contains(child.ID)) {
                            this.open.Add(child, child.ID);
                            this.open2.Add(child.ID);
                        }
                        else {
                            //Sprawdzanie czy nie można podmienić stanu w ziobrze open na taki sam stan ale z krótszą ścieżką przejścia.
                            bool isNewerBetter = false;
                            int i = this.open.Values.IndexOf(child.ID);

                            if (this.open.Keys[i].G > child.G) {
                                isNewerBetter = true;
                            }
                            if (isNewerBetter) {
                                this.open.RemoveAt(i);
                                this.open.Add(child, child.ID);
                            }
                        }
                    }
                }

                this.closed.Add(currentState.ID, currentState);

                if (this.open.Count == 1) {
                    break;
                }
                else {
                    currentState = this.open.Keys[0];


                    this.open.RemoveAt(0);
                    this.open2.Remove(currentState.ID);
                }
            }
        }


        #endregion //end Public Methods
    }
}