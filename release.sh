rm -rf cgicc-$1/*
rm -rf cgicc-$1
cd /tmp
rm -rf cgicc-$1/*
rm -rf cgicc-$1
cd -
mkdir /tmp/cgicc-$1
./autogen.sh
cp -Rf * /tmp/cgicc-$1  
mv /tmp/cgicc-$1 .
cd cgicc-$1
echo "s/NOTVERSIONNEDPACKAGE/"$1"/" >tempGen.sed
echo "Writing"
sed -f tempGen.sed configure.ac>temp2
rm configure.ac
sed -f tempGen.sed configure>temp21
rm configure
mv temp21 configure
chmod +x configure
mv temp2 configure.ac
sed -f tempGen.sed Makefile.in>temp22
rm temp2 temp21 temp22
sed -f tempGen.sed doxygen.conf>temp3
rm doxygen.conf
mv temp3 doxygen.conf
rm tempGen.se
./autogen
rm -rf CVS
rm -rf cgicc/CVS
rm -rf contrib/CVS
rm -rf demo/CVS
rm -rf demo/images/CVS
rm -rf doc/CVS
rm -rf doc/images/CVS
rm -rf example/CVS
rm -rf info/CVS
rm -rf src/CVS
rm -rf support/CVS
rm -rf test/CVS
rm -rf win/CVS

cd ..
tar -czf cgicc-$1.tar.gz cgicc-$1

