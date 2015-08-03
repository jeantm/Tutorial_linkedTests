#include <iostream>
#include <fstream>
#include <string>
#include "itkImage.h"
#include "itkRandomImageSource.h"
#include "itkImageFileWriter.h"
#include "fileCreationCLP.h"


int main(int argc, char ** argv)
{
    PARSE_ARGS ;

    if (argc != 2)
    {
        std::cerr << "Wrong Number of inputs for this main.\n" <<std::endl;
        return EXIT_FAILURE;
    }
    else
    {
        std::string outputFileName = input;

        const unsigned int Dimension = 2;
        typedef unsigned char PixelType;
        typedef itk::Image< PixelType, Dimension >  ImageType;

        ImageType::SizeType size;
        size.Fill( 512 );

        typedef itk::RandomImageSource< ImageType > RandomImageSourceType;

        RandomImageSourceType::Pointer randomImageSource = RandomImageSourceType::New();
        randomImageSource->SetNumberOfThreads(1); // to produce reproducible results
        randomImageSource->SetSize( size );

        typedef itk::ImageFileWriter< ImageType > WriterType;
        WriterType::Pointer writer = WriterType::New();
        writer->SetFileName( outputFileName );
        writer->SetInput( randomImageSource->GetOutput() );
        try
        {
            writer->Update();
        }
        catch( itk::ExceptionObject & error )
        {
            std::cerr << "Error: " << error << std::endl;
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }
}
