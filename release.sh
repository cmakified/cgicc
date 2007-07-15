rm -rf cgicc-$1/*
rm -rf cgicc-$1
cd /tmp
rm -rf cgicc-$1/*
rm -rf cgicc-$1
cd -
mkdir /tmp/cgicc-$1
cp -Rf * /tmp/cgicc-$1  
mv /tmp/cgicc-$1 .
cd cgicc-$1
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

