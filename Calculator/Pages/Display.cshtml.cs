using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace AspNetCoreExample.Pages
{
    public class DisplayModel : PageModel
    {
        public string Result { get; set; } 
        public void OnGet()
        {
            Result = Request.Query["a"].ToString();

        }
    }
}
