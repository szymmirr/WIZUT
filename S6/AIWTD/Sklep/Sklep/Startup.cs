using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(Sklep.Startup))]
namespace Sklep
{
    public partial class Startup {
        public void Configuration(IAppBuilder app) {
            ConfigureAuth(app);
        }
    }
}
