clear;
z = [0:1:47];
h = round(exp(-1i*2*pi*z*1000/48000)* 16383);
r = round(2*exp(1i*2*pi*z*1000/48000)* 16383);
lookupH = convertComplexToFloatStruct(h);
lookupR = convertComplexToFloatStruct(r);
coef = [-0.0001058247144 -0.003036818467 -0.007088692393  -0.01214145962  -0.01561728399 -0.01465814374 -0.007587981876  0.004402833525    0.0167098958   0.02270098962 0.01690693013 -0.001316639944  -0.02563640103  -0.04376792535  -0.04193049669 -0.01116868481   0.04733457416    0.1207813025     0.188363567    0.2288243324 0.2288243324     0.188363567    0.1207813025   0.04733457416  -0.01116868481  -0.04193049669  -0.04376792535  -0.02563640103 -0.001316639944   0.01690693013  0.02270098962    0.0167098958  0.004402833525 -0.007587981876  -0.01465814374 -0.01561728399  -0.01214145962 -0.007088692393 -0.003036818467 -0.0001058247144];
coefInt = round(coef * 16383);
writeIntArrayToFile(coefInt, "fdaCoef", 16383);
writeIntArrayToFile(lookupH, "H", 16383);
writeIntArrayToFile(lookupR, "R", 16383);

coef = [-0.0001058247144 -0.003036818467 -0.007088692393  -0.01214145962  -0.01561728399 -0.01465814374 -0.007587981876  0.004402833525    0.0167098958   0.02270098962 0.01690693013 -0.001316639944  -0.02563640103  -0.04376792535  -0.04193049669 -0.01116868481   0.04733457416    0.1207813025     0.188363567    0.2288243324 0.2288243324     0.188363567    0.1207813025   0.04733457416  -0.01116868481  -0.04193049669  -0.04376792535  -0.02563640103 -0.001316639944   0.01690693013  0.02270098962    0.0167098958  0.004402833525 -0.007587981876  -0.01465814374 -0.01561728399  -0.01214145962 -0.007088692393 -0.003036818467 -0.0001058247144];
t=0:1:47999;
hdouble = exp(-1i*2*pi*t*1000/48000);
rdouble = 2*exp(1i*2*pi*t*1000/48000);
a = sin(2*pi*1000*t/48000);
b = sin(2*pi*1200*t/48000);
c = sin(2*pi*950*t/48000);
x = (a+b+c)./3;

figure(1);
plot(abs(fft(x)));
x= x.*hdouble;
a = integrate(x);
b = integrate(a);
a = integrate(b);
%b=0;
b = downsample(a, 48);

a = diff(b);
b = diff(a);
inpFilter = diff(b);
a = conv(inpFilter,coef);
a(1001:end) = [];
b = diff(a);
a = diff(b);
b = diff(a);

a = upsample(b,48);

b = integrate(a);
a = integrate(b);
b = integrate(a);
b = b .* rdouble;
figure(2);
plot(abs(fft(b)));

function y = convertComplexToFloatStruct(input)
    temp = zeros(1,(size(input,2)));
    for i = 1:(size(input,2))
        temp(i*2-1) = real(input(1,i));
        temp(i*2) = imag(input(1,i));
    end
    y=temp;
end
function output = integrate(input)
    num=1;
    denom=[1 -1];
    output = filter(num, denom, input);
end
function output = diff(input)
    num=[1 -1];
    denom=1;
    output = filter(num, denom, input);
end

function writeFloatArrayToFile(array, arrayName)
    fileID = fopen(strcat(arrayName,".h"), 'w');
    preArr = strcat("float",  {' '}, arrayName, "[", int2str(size(array, 2)),"]"," = {");
    fprintf (fileID, preArr);
    fprintf (fileID, ', %f', array);
    fprintf (fileID, "};");
    fclose(fileID);
end
function writeIntArrayToFile(array, arrayName, DCgain)
    fileID = fopen(strcat(arrayName,".h"), 'w');
    preArr = strcat("int",  {' '}, arrayName, "[", int2str(size(array, 2)),"]"," = {");
    fprintf (fileID, preArr);
    fprintf (fileID, ', %i', array);
    fprintf (fileID, "};");
    fprintf (fileID, strcat("#define", {' '}, "DC_gain", arrayName, {' '} , int2str(DCgain)));
    fclose(fileID);
end