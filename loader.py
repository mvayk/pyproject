# NNNNNNNN        NNNNNNNN   SSSSSSSSSSSSSSS                AAA               
# N:::::::N       N::::::N SS:::::::::::::::S              A:::A              
# N::::::::N      N::::::NS:::::SSSSSS::::::S             A:::::A             
# N:::::::::N     N::::::NS:::::S     SSSSSSS            A:::::::A            
# N::::::::::N    N::::::NS:::::S                       A:::::::::A           
# N:::::::::::N   N::::::NS:::::S                      A:::::A:::::A          
# N:::::::N::::N  N::::::N S::::SSSS                  A:::::A A:::::A         
# N::::::N N::::N N::::::N  SS::::::SSSSS            A:::::A   A:::::A        
# N::::::N  N::::N:::::::N    SSS::::::::SS         A:::::A     A:::::A       
# N::::::N   N:::::::::::N       SSSSSS::::S       A:::::AAAAAAAAA:::::A      
# N::::::N    N::::::::::N            S:::::S     A:::::::::::::::::::::A     
# N::::::N     N:::::::::N            S:::::S    A:::::AAAAAAAAAAAAA:::::A    
# N::::::N      N::::::::NSSSSSSS     S:::::S   A:::::A             A:::::A   
# N::::::N       N:::::::NS::::::SSSSSS:::::S  A:::::A               A:::::A  
# N::::::N        N::::::NS:::::::::::::::SS  A:::::A                 A:::::A 
# NNNNNNNN         NNNNNNN SSSSSSSSSSSSSSS   AAAAAAA                   AAAAAAA

# /* imports */
import os;
import ctypes;

# /* define path */
dll_path           = os.path.abspath("libraries/main.dll");

# /* load dll into mem, fetch main() - define args & allow returning */
game               = ctypes.WinDLL(dll_path);
game.main.restype  = ctypes.c_int;
game.main.argtypes = [ ];
g_r                = game.main();