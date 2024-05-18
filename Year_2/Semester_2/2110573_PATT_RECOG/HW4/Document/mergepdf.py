import pypdf 

writer = pypdf.PdfWriter()

files = ['HW4_Code.pdf', 'HW4_Math.pdf']

for file in files[::-1]:
    writer.append(file)
writer.write('HW04_NeuralNet.pdf')