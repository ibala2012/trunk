# ~/.nixpkgs/config.nix
{
  # ~/.nixpkgs/config.nix lets us override the Nix package set
  # using packageOverrides. In this case we extend it by adding
  # new packages using myEnvFun.
  packageOverrides = pkgs : with pkgs; {
        ghc710 = pkgs.myEnvFun {
	  name = "ghc710";
<<<<<<< HEAD
	  buildInputs = [ ghc  cabal-install hdevtools];
=======
	  buildInputs = [ ghc  cabal-install vimplugin-vim-hdevtools];
>>>>>>> 81b871457754d984195d2f0519872d38754fc0d3
	};

   };
}

